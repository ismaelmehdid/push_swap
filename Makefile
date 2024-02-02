# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 21:22:51 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/02/02 23:44:27 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = ${wildcard src/errorhandling/*.c src/instructions/*.c src/sorting/*.c src/*.c}
SRCS_BONUS = ${wildcard src_bonus/errorhandling_bonus/*.c \
						src_bonus/instructions_bonus/*.c \
						src_bonus/check_instructions_bonus/*.c \
						src_bonus/*.c}

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}

$(NAME): ${OBJS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

$(NAME_BONUS): ${OBJS_BONUS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS_BONUS} ./libft/libft.a -o ${NAME_BONUS}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		@${RM} ${OBJS} ${NAME} ${OBJS_BONUS} ${NAME_BONUS}

bonus: ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
