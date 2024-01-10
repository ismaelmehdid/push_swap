# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 21:22:51 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/10 18:48:49 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ${wildcard src/errorhandling/*.c src/instructions/*.c src/sorting/*.c src/*.c}

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}

$(NAME): ${OBJS}
		@${MAKE} -C ./libft
		@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
		@${MAKE} -C ./libft fclean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re