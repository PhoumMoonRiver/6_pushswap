/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:06 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 16:41:22 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_pa(int *stack_a, int *stack_b, int len)
{
    s_count c;

    c.num1 = len;
    c.i = len;
    c.num2 = 0;
    c.i--;
    while (c.num1 >= 0)
    {
        stack_a[c.num1 + 1] = stack_a[c.num1];
        c.num1--;
    }
    stack_a[0] = stack_b[0];
    while (c.num2 < (len - c.i) + 1)
    {
        stack_b[c.num2] = stack_b[c.num2 + 1];
        c.num2++;
    }
    ft_putstr_fd("pa\n", 1);
}

void    ft_pb(int *stack_a, int *stack_b, int len)
{
    s_count c;

    c.i = 0;
    c.num1 = 1;
    c.j = 0;
    c.num2++;
    c.j = stack_a[0];
    while (c.num1 <= len)
    {
        stack_a[c.num1 - 1] = stack_a[c.num1];
        c.num1++;
    }
    c.num2 = len - (c.num1 - 2);
    while (c.i < c.num2)
    {
        stack_b[c.i + 1] = stack_b[c.i];
        c.i++;
    }
    stack_b[0] = c.j;
    ft_putstr_fd("pb\n", 1);
}