/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:51:32 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/13 17:11:53 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_all_str(int argc, char **argv)
{
	int	j;

	j = 1;
	if (argc == 2)
	{
		if (!is_all_digit(argv[1]) || ft_atoi_custom(argv[1]) > INT_MAX
			|| ft_atoi_custom(argv[1]) < INT_MIN || ft_strlen(argv[1]) == 0)
			return (0);
	}
	while (j != argc)
	{
		if (!is_all_digit(argv[j]) || ft_atoi_custom(argv[j]) > INT_MAX
			|| ft_atoi_custom(argv[1]) < INT_MIN || ft_strlen(argv[j]) == 0)
			return (0);
		j++;
	}
	if (has_duplicate(argc, argv))
		return (0);
	return (1);
}
