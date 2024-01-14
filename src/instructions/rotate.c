/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/14 18:47:32 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(struct s_stack **a, int checkCalled)
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
	if (checkCalled != 1)
		write (1, "ra\n", 3);
}

void	rb(struct s_stack **b, int checkCalled)
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
	if (checkCalled != 1)
		write (1, "rb\n", 3);
}

void	rr(struct s_stack **a, struct s_stack **b)
{
	ra(a, 1);
	rb(b, 1);
	write (1, "rr\n", 3);
}
