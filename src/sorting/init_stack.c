/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:40:05 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/14 18:59:48 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(struct s_stack **a, int argc, char **argv)
{
	int	temp;

	temp = 0;
	while (argc > 1)
	{
		temp = ft_atoi_custom(argv[argc - 1]);
		add_to_stack(a, temp);
		argc--;
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
