/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:17:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 17:01:11 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_lenght(struct s_stack *stack)
{
	int	lenght;

	lenght = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		lenght++;
	}
	return (lenght);
}

int	list_is_sorted(struct s_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (!stack->next)
			return (1);
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push(struct s_stack **stack, int data)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	newnode->data = data;
	newnode->next = *stack;
	*stack = newnode;
}

int	pop(struct s_stack **stack)
{
	t_stack	*top;
	int		topnode;

	if (!*stack)
		return (-1);
	top = *stack;
	topnode = top->data;
	*stack = top->next;
	free (top);
	return (topnode);
}
