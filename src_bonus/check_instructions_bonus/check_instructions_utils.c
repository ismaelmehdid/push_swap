/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:19:34 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 23:07:35 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	compare_strings(char *one, char *two)
{
	int	i;

	i = 0;
	if (ft_strlen(one) != ft_strlen(two))
		return (false);
	while (one[i])
	{
		if (one[i] != two[i])
			return (false);
		i++;
	}
	return (true);
}

int	reading_fd_zero(ssize_t *rd_size, char *buffer, char **content, char **new)
{
	*new = malloc(ft_strlen(*content) + (*rd_size) + 1);
	if (!*new)
	{
		free (*content);
		return (0);
	}
	ft_strlcpy(*new, *content, ft_strlen(*content) + 1);
	ft_strlcat(*new, buffer, ft_strlen(*new) + ft_strlen(buffer) + 1);
	free(*content);
	*content = *new;
	*rd_size = read(0, buffer, 1024 - 1);
	buffer[*rd_size] = '\0';
	return (1);
}

int	double_array_size(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}
