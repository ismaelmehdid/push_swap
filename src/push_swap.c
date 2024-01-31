/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 18:13:18 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**list;

	a = NULL;
	b = NULL;
	if (argc != 2)
		return (0);
	list = convert_list(argv[1]);
	if (!list)
		return (0);
	if (!check_all_str(list))
		program_exit(a, b, list, 1);
	init_stack(&a, list);
	if (list_is_sorted(a))
		program_exit(a, b, list, 0);
	sort_stack(&a, &b);
	program_exit(a, b, list, 0);
	return (0);
}
