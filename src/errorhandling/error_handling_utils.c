/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:58:08 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/31 17:35:51 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp_custom(const char *s1, const char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

long	ft_atoi_custom(const char *str)
{
	int		i;
	long	temp;
	int		countm;

	countm = 0;
	temp = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
		|| str[i] == '+' || str[i] == '-')
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] == '+' || str[i + 1] == '-'
				|| (str[i + 1] >= 9 && str[i + 1] <= 13) || str[i + 1] == 32))
			return (0);
		if (str[i] == '-')
			countm++;
		i++;
	}
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		temp = temp * 10 + str[i++] - '0';
	if (countm == 1)
		return (-temp);
	return (temp);
}

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(char **list)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = 0;
	while (list[length])
		length++;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_strcmp_custom(list[i], list[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
