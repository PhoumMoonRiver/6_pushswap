# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 12:32:51 by njerasea          #+#    #+#              #
#    Updated: 2022/10/15 12:11:45 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = pushswap.c \
		error_check.c \
		libft_and_util/1_libft_util.c \
		libft_and_util/ft_split.c \
		libft_and_util/ft_util.c \
		action/ft_swap.c \
		action/ft_rotate.c \
		action/rev_rotate.c \
		action/ft_push.c \
		sort/pushint.c \
		sort/sort.c \
		sort/3_sort.c \
		sort/5_sort.c \
		sort/100_sort.c \
		sort/500_sort.c \
		sort/universe_sort.c \
		sort/sub_sort.c

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

test: checker_OS
	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

.PHONY: all clean fclean re
