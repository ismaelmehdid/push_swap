/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 21:40:49 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ra(struct s_stack **a)
{
	t_stack	*last;
	t_stack	*temp;

	if (!a)
		return ;
	last = *a;
	temp = *a;
	if (list_lenght(*a) < 2)
		return ;
	while (last->next)
		last = last->next;
	temp->next->prev = NULL;
	*a = temp->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	rb(struct s_stack **b)
{
	t_stack	*last;
	t_stack	*temp;

	if (!b)
		return ;
	last = *b;
	temp = *b;
	if (list_lenght(*b) < 2)
		return ;
	while (last->next)
		last = last->next;
	temp->next->prev = NULL;
	*b = temp->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}

void	rr(struct s_stack **a, struct s_stack **b)
{
	ra(a);
	rb(b);
}
