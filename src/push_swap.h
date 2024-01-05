/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:18:03 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/05 23:02:26 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //TODO

typedef struct s_node{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_list{
	struct s_node	*head;
	struct s_node	*tail;
}t_list;

int		check_all_str(int argc, char **argv);

int		ft_strcmp_custom(const char *s1, const char *s2);

int		is_all_digit(char *str);

int		has_duplicate(int argc, char **argv);

long	ft_atoi_custom(const char *str);

#endif