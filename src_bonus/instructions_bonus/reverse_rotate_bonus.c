/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:41:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 21:40:11 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	rra(struct s_stack **a)
{
	t_stack	*last;
	t_stack	*head;

	if (!a)
		return ;
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
}

void	rrb(struct s_stack **b)
{
	t_stack	*last;
	t_stack	*head;

	if (!b)
		return ;
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
}

void	rrr(struct s_stack **a, struct s_stack **b)
{
	rra(a);
	rrb(b);
}
