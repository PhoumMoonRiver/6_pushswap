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

BONUS_NAME = checker

SRC = 	error_check.c \
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

SRCS = pushswap.c $(SRC)

BONUS_SRCS = 	checker_bonus/bonus_checker_main.c \
				checker_bonus/get_next_line/get_next_line_utils.c \
				checker_bonus/get_next_line/get_next_line.c \
				$(SRC)

CC = gcc -Wall -Wextra -Werror -std=c99

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME):
	$(CC) $(BONUS_SRCS) -o $(BONUS_NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
