/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:04 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/12 21:55:33 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

struct s_stack *maxData(struct s_stack *stack)
{
	t_stack *max;
	
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

struct s_stack	*cheapestCost(struct s_stack *stack)
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

void	miniSort(struct s_stack **stack)
{
	t_stack	*max;
	t_stack	*temp;

	temp = *stack;
	max = maxData(*stack);
	if (!stack)
		return ;
	while (temp->next->next != max)
		ra(stack, 0);
	if (!list_is_sorted(*stack))
		sa(stack, 0);
}

struct s_stack *minData(struct s_stack *stack)
{
	t_stack *min;
	
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