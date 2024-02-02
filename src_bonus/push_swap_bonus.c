/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:55:39 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 21:43:27 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**list;
	int		status;

	a = NULL;
	b = NULL;
	status = 0;
	if (argc != 2)
		return (0);
	list = convert_list(argv[1]);
	if (!list || !double_array_size(list))
		program_exit(a, b, list, status);
	if (!check_all_str(list))
		program_exit(a, b, list, 1);
	init_stack(&a, list);
	status = check_instructions(&a, &b);
	program_exit(a, b, list, status);
	return (0);
}
