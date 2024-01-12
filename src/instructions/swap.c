/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:44 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/12 21:31:50 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(struct s_stack **a, int checkCalled)
{
	t_stack	*temp;
	
	temp = *a;
	if (list_lenght(*a) <= 1)
		return ;
	temp->next->prev = NULL;
	*a = temp->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp->prev = *a;
	temp->next->prev = temp;
	if (checkCalled != 1)
		write (1, "sa\n", 3);
}

void	sb(struct s_stack **b, int checkCalled)
{
	t_stack	*temp;
	
	temp = *b;
	if (list_lenght(*b) <= 1)
		return ;
	temp->next->prev = NULL;
	*b = temp->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	temp->prev = *b;
	temp->next->prev = temp;
	if (checkCalled != 1)
		write (1, "sb\n", 3);
}

void	ss(struct s_stack **a, struct s_stack **b)
{
	sa(a, 1);
	sa(b, 1);
	write (1, "ss\n", 3);
}
