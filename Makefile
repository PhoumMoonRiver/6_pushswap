# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 12:32:51 by njerasea          #+#    #+#              #
#    Updated: 2022/09/27 12:16:38 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = pushswap.c \
		error_check.c \
		1_libft_util.c \
		ft_split.c \
		pushint.c \
		ft_util.c \
		ft_swap.c \
		ft_rotate.c \
		rev_rotate.c \
		ft_push.c 

CC = gcc -Wall -Wextra -Werror -std=c99 -g

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re