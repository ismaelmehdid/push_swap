/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/06 23:27:59 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void list_display(struct s_stack *a)
{
	if (!a)
	{
		printf("la liste est vide :((");
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
	//t_stack *b;

	a = NULL;
	//b = NULL;
	if (argc <= 1)
		return (0);
	if (!check_all_str(argc, argv))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(&a, argc, argv);
	list_display(a);
	/*Init list list_init(struct s_list stack_a)*/
	/*Check if the stack a is sorted*/
	/*Sort list list_sort(struct s_list stack_a, struct s_list stack_b)*/
	return (0);
}
