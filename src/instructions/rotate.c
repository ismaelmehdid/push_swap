/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:38 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/07 19:19:28 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(struct s_stack *a)
{
	if (list_lenght(a) < 2)
		return ;
	while (a->next)
	{
		sa(a);
		a = a->next;
	}
}

void	rb(struct s_stack *b)
{
	if (list_lenght(b) < 2)
		return ;
	while (b->next)
	{
		sa(b);
		b = b->next;
	}
}

void	rr(struct s_stack *a, struct s_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(struct s_stack *a)
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
}

void	rrb(struct s_stack *b)
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

}

void	rrr(struct s_stack *a, struct s_stack *b)
{
	rra(a);
	rrb(b);
}
