/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:57:51 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/12 22:42:42 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
static void list_display(struct s_stack *a)
{
	if (!a)
	{
		printf("la liste est vide :(\n");
		return ;
	}
	while (a)
	{
		printf("data:%d target:%d cost:%d\n", a->data, a->target->data, a->cost);
		a = a->next;
	}
	printf("NULL");
}
*/
void	sortStack(struct s_stack **a, struct s_stack **b)
{
	transfertFirstTwo(a, b);
	while (list_lenght(*a) != 3)
	{
		setIndexAndMedian(*a);
		setIndexAndMedian(*b);
		setTargetA(*a, *b);
		setPushCostA(*a, *b);
		transfertAtoB(a, b);
	}
	miniSort(a);
	while (list_lenght(*b) != 0)
	{

		setIndexAndMedian(*a);
		setIndexAndMedian(*b);
		setTargetB(*a, *b);
		setPushCostB(*a, *b);
		transfertBtoA(a, b);
	}
	setIndexAndMedian(*a);
	putMinOnTop(a);
}

void	putMinOnTop(struct  s_stack **a)
{
	t_stack	*minNode;

	minNode = minData(*a);
	while (*a != minNode)
	{
		if (minNode->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	transfertFirstTwo(struct s_stack **a, struct s_stack **b)
{
	int	lenght;
	int	i;

	lenght = list_lenght(*a);
	i = 0;
	while (i != 2)
	{
		if (lenght == 3 || lenght == 2)
			break ;
		pb(a, b);
		lenght--;
		i++;
	}
}

void	setTargetA(struct s_stack *a, struct s_stack *b)
{
	t_stack *mintarget;
	t_stack *currentb;

	while (a)
	{
		mintarget = NULL;
		currentb = b;
		while(currentb)
		{
			if (currentb->data < a->data && (mintarget == NULL
			|| currentb->data > mintarget->data))
				mintarget = currentb;
			currentb = currentb->next;
		}
		if (mintarget == NULL)
			a->target = maxData(b);
		else
			a->target = mintarget;
		a = a->next;
	}
}

void	setTargetB(struct s_stack *a, struct s_stack *b)
{
	t_stack *mintarget;
	t_stack *currenta;

	while (b)
	{
		mintarget = NULL;
		currenta = a;
		while(currenta)
		{
			if (currenta->data > b->data && (mintarget == NULL
			|| currenta->data < mintarget->data))
				mintarget = currenta;
			currenta = currenta->next;
		}
		if (mintarget == NULL)
			b->target = minData(a);
		else
			b->target = mintarget;
		b = b->next;
	}
}

void	setPushCostB(struct s_stack *a, struct s_stack *b)
{
	int	lenghta;
	int	lenghtb;

	lenghta = list_lenght(a);
	lenghtb = list_lenght(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = lenghtb - b->index;
		if (b->target->above_median == 1)
			b->cost = b->cost + b->target->index;
		else
			b->cost = b->cost + (lenghta - b->target->index);
		b = b->next;
	}
}

void	setPushCostA(struct s_stack *a, struct s_stack *b)
{
	int	lenghta;
	int	lenghtb;

	lenghta = list_lenght(a);
	lenghtb = list_lenght(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = lenghta - a->index;
		if (a->target->above_median == 1)
			a->cost = a->cost + a->target->index;
		else
			a->cost = a->cost + (lenghtb - a->target->index);
		a = a->next;
	}
}

void	setIndexAndMedian(struct s_stack *thestack)
{
	int	median;
	int	index;
	
	if (!thestack)
		return ;
	median = list_lenght(thestack) / 2;
	index = 0;
	while (thestack)
	{
		thestack->index = index;
		if (thestack->index == 0)
			thestack->prev = NULL;
		if (thestack->next != NULL)
			thestack->next->prev = thestack;
		if (index <= median)
			thestack->above_median = 1;
		else
			thestack->above_median = 0;
		index++;
		thestack = thestack->next;
	}
}

void	transfertBtoA(struct s_stack **a, struct  s_stack **b)
{
	t_stack	*cheapest;

	cheapest = cheapestCost(*b);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*b != cheapest && *a != cheapest->target)
		{
			rr(a, b);
			setIndexAndMedian(*a);
			setIndexAndMedian(*b);
		}
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*a != cheapest->target && *b != cheapest)
		{
			rrr(a, b);
			setIndexAndMedian(*a);
			setIndexAndMedian(*b);
		}
	}
	putOnTopA(a, cheapest->target);
	putOnTopB(b, cheapest);
	pa(a, b);
}

void	transfertAtoB(struct s_stack **a, struct  s_stack **b)
{
	t_stack	*cheapest;

	cheapest = cheapestCost(*a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*a != cheapest && *b != cheapest->target)
		{
			rr(a, b);
			setIndexAndMedian(*a);
			setIndexAndMedian(*b);
		}
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			rrr(a, b);
			setIndexAndMedian(*a);
			setIndexAndMedian(*b);
		}
	}
	putOnTopA(a, cheapest);
	putOnTopB(b, cheapest->target);
	pb(a, b);
}

void	putOnTopA(struct s_stack **a, struct s_stack *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a, 0);
		else
			rra(a, 0);
		setIndexAndMedian(*a);
	}
}

void	putOnTopB(struct s_stack **b, struct s_stack *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b, 0);
		else
			rrb(b, 0);
		setIndexAndMedian(*b);
	}
}