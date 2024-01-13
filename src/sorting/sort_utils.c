/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:04 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:27:18 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct s_stack	*max_data(struct s_stack *stack)
{
	t_stack	*max;

	max = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (max == NULL)
			max = stack;
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

struct s_stack	*min_data(struct s_stack *stack)
{
	t_stack	*min;

	min = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (min == NULL)
			min = stack;
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

struct s_stack	*cheapest_cost(struct s_stack *stack)
{
	t_stack	*cheapest;

	cheapest = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (cheapest == NULL)
			cheapest = stack;
		if (cheapest->cost > stack->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	mini_sort(struct s_stack **stack)
{
	t_stack	*max;
	t_stack	*temp;

	temp = *stack;
	max = max_data(*stack);
	if (!stack)
		return ;
	while (temp->next->next != max)
		ra(stack, 0);
	if (!list_is_sorted(*stack))
		sa(stack, 0);
}

void	set_index_and_median(struct s_stack *thestack)
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
