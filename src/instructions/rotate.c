/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/10 17:27:43 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(struct s_stack *a, int checkCalled)
{
	if (list_lenght(a) < 2)
		return ;
	while (a->next)
	{
		sa(a, 1);
		a = a->next;
	}
	if (checkCalled != 1)
		write (1, "ra\n", 3);
}

void	rb(struct s_stack *b, int checkCalled)
{
	if (list_lenght(b) < 2)
		return ;
	while (b->next)
	{
		sa(b, 1);
		b = b->next;
	}
	if (checkCalled != 1)
		write (1, "rb\n", 3);
}

void	rr(struct s_stack *a, struct s_stack *b)
{
	ra(a, 1);
	rb(b, 1);
}

void	rra(struct s_stack *a, int checkCalled)
{
	int	temp;

	temp = 0;
	if (list_lenght(a) < 2)
		return ;
	while (a->next)
		a = a->next;
	while (a->prev)
	{
		temp = a->data;
		a->data = a->prev->data;
		a->prev->data = temp;
		a = a->prev;
	}
	if (checkCalled != 1)
		write (1, "rra\n", 4);
}

void	rrb(struct s_stack *b, int checkCalled)
{
	int	temp;

	temp = 0;
	if (list_lenght(b) < 2)
		return ;
	while (b->next)
		b = b->next;
	while (b->prev)
	{
		temp = b->data;
		b->data = b->prev->data;
		b->prev->data = temp;
		b = b->prev;
	}
	if (checkCalled != 1)
		write (1, "rrb\n", 4);

}

void	rrr(struct s_stack *a, struct s_stack *b)
{
	rra(a, 1);
	rrb(b, 1);
}
