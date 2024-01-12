/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/12 22:53:53 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeAllNodes(struct s_stack *a, struct s_stack *b)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (!check_all_str(argc, argv))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(&a, argc, argv);
	if (list_is_sorted(a))
		return (0);
	sortStack(&a, &b);
	freeAllNodes(a, b);
	return (0);
}
