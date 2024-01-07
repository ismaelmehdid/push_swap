/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:47:42 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/07 17:34:55 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(struct s_stack **a, struct s_stack **b)
{
	t_stack	*newnode;
	int		datapoped;
	
	datapoped = 0;
	if (list_lenght(*b) == 0)
		return ;
	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	datapoped = pop(b);
	push(a, datapoped);
}

void	pb(struct s_stack **a, struct s_stack **b)
{
	t_stack	*newnode;
	int		datapoped;
	
	datapoped = 0;
	if (list_lenght(*a) == 0)
		return ;
	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return ;
	datapoped = pop(a);
	push(b, datapoped); 
}