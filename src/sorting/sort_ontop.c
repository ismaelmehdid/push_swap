/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ontop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:54:14 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:30:50 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_on_top_a(struct s_stack **a, struct s_stack *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a, 0);
		else
			rra(a, 0);
		set_index_and_median(*a);
	}
}

void	put_on_top_b(struct s_stack **b, struct s_stack *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b, 0);
		else
			rrb(b, 0);
		set_index_and_median(*b);
	}
}

void	put_min_on_top(struct s_stack **a)
{
	t_stack	*min_node;

	min_node = min_data(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
