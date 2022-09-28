/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:39:25 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/28 10:56:36 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include               <stdio.h>
# include               <string.h>

typedef struct t_count
{
    int  fd;
    int  sd;
    int  i;
    int  j;
    int num1;
    int num2;
} s_count;

char    error_check(int ac, char **av);
char    check_dup(int *res_num);
void	ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(char *s);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int     ft_ma_count(char **av);
int     *ft_pushint(char **av, int len);
void ft_free2d(char **free2);
void    ft_sa(int *stack_a, int len);
void    ft_sb(int *stack_a, int len);
void    ft_ss(int *stack_a, int *stack_b, int len);
void    ft_ra(int *stack_a, int len);
void    ft_rb(int *stack_b, int len);
void    ft_rr(int *stack_a, int *stack_b, int len);
void    ft_rra(int *stack_a, int len);
void    ft_rrb(int *stack_b, int len);
void    ft_rrr(int *stack_a, int *stack_b, int len);
void    ft_pa(int *stack_a, int *stack_b, int len);
void    ft_pb(int *stack_a, int *stack_b, int len);
#endif