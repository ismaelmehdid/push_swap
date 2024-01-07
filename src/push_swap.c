/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/07 19:02:18 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void list_display(struct s_stack *a)
{
	if (!a)
	{
		printf("la liste est vide :(\n");
		return ;
	}
	while (a)
	{
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf("NULL");
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
	list_display(a);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	rra(a);
	list_display(a);
	if (list_is_sorted(a))
		return (0);
	/*Sort list list_sort(struct s_list stack_a, struct s_list stack_b)*/
	return (0);
}
