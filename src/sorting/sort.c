/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:57:51 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:29:55 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(struct s_stack **a, struct s_stack **b)
{
	transfert_first_two(a, b);
	while (list_lenght(*a) != 3)
	{
		set_index_and_median(*a);
		set_index_and_median(*b);
		set_target_a(*a, *b);
		set_push_cost_a(*a, *b);
		transfert_a_to_b(a, b);
	}
	mini_sort(a);
	while (list_lenght(*b) != 0)
	{
		set_index_and_median(*a);
		set_index_and_median(*b);
		set_target_b(*a, *b);
		set_push_cost_b(*a, *b);
		transfert_b_to_a(a, b);
	}
	set_index_and_median(*a);
	put_min_on_top(a);
}

void	transfert_a_to_b(struct s_stack **a, struct s_stack **b)
{
	t_stack	*cheapest;

	cheapest = cheapest_cost(*a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*a != cheapest && *b != cheapest->target)
		{
			rr(a, b);
			set_index_and_median(*a);
			set_index_and_median(*b);
		}
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			rrr(a, b);
			set_index_and_median(*a);
			set_index_and_median(*b);
		}
	}
	put_on_top_a(a, cheapest);
	put_on_top_b(b, cheapest->target);
	pb(a, b);
}

void	transfert_b_to_a(struct s_stack **a, struct s_stack **b)
{
	t_stack	*cheapest;

	cheapest = cheapest_cost(*b);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*b != cheapest && *a != cheapest->target)
		{
			rr(a, b);
			set_index_and_median(*a);
			set_index_and_median(*b);
		}
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*a != cheapest->target && *b != cheapest)
		{
			rrr(a, b);
			set_index_and_median(*a);
			set_index_and_median(*b);
		}
	}
	put_on_top_a(a, cheapest->target);
	put_on_top_b(b, cheapest);
	pa(a, b);
}
