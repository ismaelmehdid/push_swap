/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:51:32 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:26:02 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_target_a(struct s_stack *a, struct s_stack *b)
{
	t_stack	*mintarget;
	t_stack	*currentb;

	while (a)
	{
		mintarget = NULL;
		currentb = b;
		while (currentb)
		{
			if (currentb->data < a->data && (mintarget == NULL
					|| currentb->data > mintarget->data))
				mintarget = currentb;
			currentb = currentb->next;
		}
		if (mintarget == NULL)
			a->target = max_data(b);
		else
			a->target = mintarget;
		a = a->next;
	}
}

void	set_target_b(struct s_stack *a, struct s_stack *b)
{
	t_stack	*mintarget;
	t_stack	*currenta;

	while (b)
	{
		mintarget = NULL;
		currenta = a;
		while (currenta)
		{
			if (currenta->data > b->data && (mintarget == NULL
					|| currenta->data < mintarget->data))
				mintarget = currenta;
			currenta = currenta->next;
		}
		if (mintarget == NULL)
			b->target = min_data(a);
		else
			b->target = mintarget;
		b = b->next;
	}
}

void	set_push_cost_a(struct s_stack *a, struct s_stack *b)
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

void	set_push_cost_b(struct s_stack *a, struct s_stack *b)
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

void	transfert_first_two(struct s_stack **a, struct s_stack **b)
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
