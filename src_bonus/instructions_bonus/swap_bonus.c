/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:44 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 21:40:48 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	sa(struct s_stack **a)
{
	t_stack	*temp;

	if (!a)
		return ;
	temp = *a;
	if (list_lenght(*a) <= 1)
		return ;
	temp->next->prev = NULL;
	*a = temp->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp->prev = *a;
	if (temp->next)
		temp->next->prev = temp;
}

void	sb(struct s_stack **b)
{
	t_stack	*temp;

	if (!b)
		return ;
	temp = *b;
	if (list_lenght(*b) <= 1)
		return ;
	temp->next->prev = NULL;
	*b = temp->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	temp->prev = *b;
	if (temp->next)
		temp->next->prev = temp;
}

void	ss(struct s_stack **a, struct s_stack **b)
{
	sa(a);
	sa(b);
}
