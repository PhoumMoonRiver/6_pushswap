/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:12:38 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 10:21:08 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_sa(int *stack_a, int len)
{
    s_count c;

    if(len == 1)
        exit(0);
    c.num1 = stack_a[0];
    stack_a[0] = stack_a[1];
    stack_a[1] = c.num1;
    ft_putstr_fd("sa\n", 1);
}

void    ft_sb(int *stack_b, int len)
{
    s_count c;

    if(len == 1)
        exit(0);
    c.num1 = stack_b[0];
    stack_b[0] = stack_b[1];
    stack_b[1] = c.num1;
    ft_putstr_fd("sb\n", 1);
}

void    ft_ss(int *stack_a, int *stack_b, int len)
{
    ft_sa(stack_a, len);
    ft_sb(stack_b, len);
    ft_putstr_fd("ss\n", 1);
}