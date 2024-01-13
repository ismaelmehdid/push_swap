/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:41:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:11:28 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(struct s_stack **a, int checkCalled)
{
	t_stack	*last;
	t_stack	*head;

	head = *a;
	last = *a;
	if (list_lenght(*a) < 2)
		return ;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*a = last;
	if (checkCalled != 1)
		write (1, "rra\n", 4);
}

void	rrb(struct s_stack **b, int checkCalled)
{
	t_stack	*last;
	t_stack	*head;

	head = *b;
	last = *b;
	if (list_lenght(*b) < 2)
		return ;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*b = last;
	if (checkCalled != 1)
		write (1, "rrb\n", 4);
}

void	rrr(struct s_stack **a, struct s_stack **b)
{
	rra(a, 1);
	rrb(b, 1);
	write (1, "rrr\n", 4);
}
