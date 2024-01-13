/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 19:45:28 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		argv = convert_to_darray(&argc, argv);
	if (!check_all_str(argc, argv))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(&a, argc, argv);
	if (list_is_sorted(a))
		return (0);
	sort_stack(&a, &b);
	free_all_nodes(a, b);
	return (0);
}
