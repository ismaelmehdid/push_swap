/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:58:35 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 18:25:36 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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
	exit(EXIT_SUCCESS);
}
