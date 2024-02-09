/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:18:03 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/02/02 23:44:15 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

void			sa(struct s_stack **a);
void			sb(struct s_stack **b);
void			ss(struct s_stack **a, struct s_stack **b);
void			pa(struct s_stack **a, struct s_stack **b);
void			pb(struct s_stack **a, struct s_stack **b);
void			ra(struct s_stack **a);
void			rb(struct s_stack **b);
void			rr(struct s_stack **a, struct s_stack **b);
void			rra(struct s_stack **a);
void			rrb(struct s_stack **b);
void			rrr(struct s_stack **a, struct s_stack **b);

int				pop(struct s_stack **stack);
void			push(struct s_stack **stack, int data);

void			init_stack(struct s_stack **a, char **list);
void			add_to_stack(struct s_stack **a, int temp);

int				list_lenght(struct s_stack *stack);
int				list_is_sorted(struct s_stack *stack);
int				check_instructions(t_stack **a, t_stack **b);
int				is_all_digit(char *str);
int				has_duplicate(char **list);
long			ft_atoi_custom(const char *str);
char			**convert_list(char *list);
int				check_all_str(char **list);
int				reading_fd_zero(ssize_t *rd_size, char *buffer,
					char **content, char **new);
bool			compare_strings(char *one, char *two);
void			free_double_array(char **array);
int				double_array_size(char **array);

void			program_exit(t_stack *a, t_stack *b, char **list, int code);

#endif
