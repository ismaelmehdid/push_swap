/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:18:03 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/06 21:48:46 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483647

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //TODO

typedef struct s_stack{
	int				data;
	int				index;
	int				cost;
	int				above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

int		check_all_str(int argc, char **argv);

int		ft_strcmp_custom(const char *s1, const char *s2);

int		is_all_digit(char *str);

int		has_duplicate(int argc, char **argv);

long	ft_atoi_custom(const char *str);

void	init_stack(struct s_stack **a, int argc, char **argv);

void	add_to_stack(struct s_stack **a, int temp);

#endif