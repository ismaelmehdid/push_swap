/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:18:03 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/10 19:04:53 by ismaelmehdi      ###   ########.fr       */
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

int		list_lenght(struct s_stack *stack);

int		list_is_sorted(struct s_stack *stack);

/*Instructions*/
void	sa(struct s_stack *a, int checkCalled);
void	sb(struct s_stack *b, int checkCalled);
void	ss(struct s_stack *a, struct s_stack *b);
void	pa(struct s_stack **a, struct s_stack **b);
void	pb(struct s_stack **a, struct s_stack **b);
void	ra(struct s_stack *a, int checkCalled);
void	rb(struct s_stack *b, int checkCalled);
void	rr(struct s_stack *a, struct s_stack *b);
void	rra(struct s_stack *a, int checkCalled);
void	rrb(struct s_stack *b, int checkCalled);
void	rrr(struct s_stack *a, struct s_stack *b);
/*------------*/

int		pop(struct s_stack **stack);

void	push(struct s_stack **stack, int data);

void	transfertFirstTwo(struct s_stack **a, struct s_stack **b);
void	sortStack(struct s_stack **a, struct s_stack **b);
void	setTargetA(struct s_stack *a, struct s_stack *b);
#endif