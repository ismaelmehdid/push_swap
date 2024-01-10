/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:57:51 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/10 21:15:23 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sortStack(struct s_stack **a, struct s_stack **b)
{
	transfertFirstTwo(a, b);
	while (list_lenght(a) != 3)
	{
		setIndexAndMedian(a);
		setIndexAndMedian(b);
		setTargetA(*a, *b);
		setPushCostAndTransfert(*a, *b);
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
	t_stack *max;

	if ((b->data) > (b->next->data))
		max = b;
	else
		max = b->next;
	while (a)
	{
		if (abs(b->data - a->data) < abs(b->next->data - a->data))
			a->target = b;
		else
			a->target = b->next;
		if ((a->data < b->data) && (a->data < b->next->data))
			a->target = max;
		a = a->next;
	}
}

void	setPushCost(struct s_stack *a, struct s_stack *b)
{
	
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
		if (index <= median)
			thestack->above_median = 0;
		else
			thestack->above_median = 1;
		thestack->index = index;
		index++;
		thestack = thestack->next;
	}
}