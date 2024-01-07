/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:44 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/07 19:14:13 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(struct s_stack *a)
{
	int	temp;

	temp = 0;
	if (list_lenght(a) == 1 || list_lenght(a) == 0)
		return ;
	temp = a->data;
	a->data = a->next->data;
	a->next->data = temp;
}

void	sb(struct s_stack *b)
{
	int	temp;

	temp = 0;
	if (list_lenght(b) == 1 || list_lenght(b) == 0)
		return ;
	temp = b->data;
	b->data = b->next->data;
	b->next->data = temp;
}

void	ss(struct s_stack *a, struct s_stack *b)
{
	sa(a);
	sa(b);
}
