/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:44 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/10 17:24:38 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(struct s_stack *a, int checkCalled)
{
	int	temp;

	temp = 0;
	if (list_lenght(a) == 1 || list_lenght(a) == 0)
		return ;
	temp = a->data;
	a->data = a->next->data;
	a->next->data = temp;
	if (checkCalled != 1)
		write (1, "sa\n", 3);
}

void	sb(struct s_stack *b, int checkCalled)
{
	int	temp;

	temp = 0;
	if (list_lenght(b) == 1 || list_lenght(b) == 0)
		return ;
	temp = b->data;
	b->data = b->next->data;
	b->next->data = temp;
	if (checkCalled != 1)
		write (1, "sb\n", 3);
}

void	ss(struct s_stack *a, struct s_stack *b)
{
	sa(a, 1);
	sa(b, 1);
}
