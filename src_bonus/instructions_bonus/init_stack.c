/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:40:05 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 22:13:09 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	init_stack(struct s_stack **a, char **list)
{
	int	temp;
	int	length;

	temp = 0;
	length = 0;
	while (list[length])
		length++;
	while (length - 1 >= 0)
	{
		temp = ft_atoi_custom(list[length - 1]);
		add_to_stack(a, temp);
		length--;
	}
}

void	add_to_stack(struct s_stack **a, int temp)
{
	t_stack	*node;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->data = temp;
	node->next = *a;
	node->prev = NULL;
	if (*a)
		(*a)->prev = node;
	*a = node;
}
