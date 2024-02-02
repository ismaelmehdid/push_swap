/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 16:44:45 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(struct s_stack **a, struct s_stack **b)
{
	int		datapoped;

	if (!b)
		return ;
	datapoped = 0;
	if (list_lenght(*b) == 0)
		return ;
	datapoped = pop(b);
	push(a, datapoped);
}

void	pb(struct s_stack **a, struct s_stack **b)
{
	int		datapoped;

	if (!a)
		return ;
	datapoped = 0;
	if (list_lenght(*a) == 0)
		return ;
	datapoped = pop(a);
	push (b, datapoped);
}
