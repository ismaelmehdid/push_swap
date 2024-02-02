/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:58:35 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 21:33:57 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_all_nodes(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		temp = temp->next;
		free(a);
		a = temp;
	}
	temp = b;
	while (temp)
	{
		temp = temp->next;
		free(b);
		b = temp;
	}
}

void	program_exit(t_stack *a, t_stack *b, char **list, int code)
{
	if (list)
		free_double_array(list);
	free_all_nodes(a, b);
	if (code == 1)
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (code == 2)
	{
		write (2, "KO\n", 3);
		exit(EXIT_FAILURE);
	}
	else if (code == 3)
	{
		write (2, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
}
