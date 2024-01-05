/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:19:18 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/05 21:30:28 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!check_all_str(argc, argv))
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}
