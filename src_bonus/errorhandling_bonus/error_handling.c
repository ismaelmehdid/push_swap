/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:51:32 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 21:05:20 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	**convert_list(char *list)
{
	char	**newlist;

	newlist = ft_split(list, ' ');
	return (newlist);
}

int	check_all_str(char **list)
{
	int	j;

	j = 0;
	while (list[j])
	{
		if (!is_all_digit(list[j]) || ft_atoi_custom(list[j]) > INT_MAX
			|| ft_atoi_custom(list[j]) < INT_MIN || ft_strlen(list[j]) == 0)
			return (0);
		j++;
	}
	if (has_duplicate(list))
		return (0);
	return (1);
}
