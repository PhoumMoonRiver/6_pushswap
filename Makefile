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
		libft_and_util/1_libft_util.c \
		libft_and_util/ft_split.c \
		sort/pushint.c \
		libft_and_util/ft_util.c \
		action/ft_swap.c \
		action/ft_rotate.c \
		action/rev_rotate.c \
		action/ft_push.c \
		sort/sort.c \
		sort/3_sort.c

CC = gcc -Wall -Wextra -Werror -std=c99

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