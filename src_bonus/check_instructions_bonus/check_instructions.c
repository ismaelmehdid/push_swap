/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:08:20 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 22:51:55 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	free_all(char *instructions, char **operations)
{
	free(instructions);
	free_double_array(operations);
}

static int	execute_instructions(t_stack **a, t_stack **b, char *line)
{
	if (compare_strings(line, "sa"))
		sa(a);
	else if (compare_strings(line, "sb"))
		sb(b);
	else if (compare_strings(line, "ss"))
		ss(a, b);
	else if (compare_strings(line, "pa"))
		pa(a, b);
	else if (compare_strings(line, "pb"))
		pb(a, b);
	else if (compare_strings(line, "ra"))
		ra(a);
	else if (compare_strings(line, "rb"))
		rb(b);
	else if (compare_strings(line, "rr"))
		rr(a, b);
	else if (compare_strings(line, "rra"))
		rra(a);
	else if (compare_strings(line, "rrb"))
		rrb(b);
	else if (compare_strings(line, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static char	*read_all_stdin(void)
{
	char		buffer[1024];
	char		*content;
	char		*new_content;
	ssize_t		read_size;

	content = malloc(1);
	if (!content)
		return (NULL);
	content[0] = '\0';
	read_size = read(0, buffer, 1024 - 1);
	buffer[read_size] = '\0';
	while (read_size > 0)
	{
		if (!reading_fd_zero(&read_size, buffer, &content, &new_content))
			return (NULL);
	}
	if (read_size == -1)
	{
		free (content);
		return (NULL);
	}
	return (content);
}

int	check_instructions(t_stack **a, t_stack **b)
{
	char	*instructions;
	char	**operations;
	int		j;

	j = 0;
	instructions = read_all_stdin();
	if (!instructions)
		return (1);
	operations = ft_split(instructions, '\n');
	while (operations[j])
	{
		if (!execute_instructions(a, b, operations[j]))
		{
			free_all(instructions, operations);
			return (1);
		}
		j++;
	}
	free_all(instructions, operations);
	if (list_is_sorted(*a) && list_lenght(*b) == 0)
		return (3);
	return (2);
}
