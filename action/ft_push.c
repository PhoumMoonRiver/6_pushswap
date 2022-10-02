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

#include "../pushswap.h"

void    ft_pa(int *stack_a, int *stack_b)
{
    s_count c;

    c.i = c.size_a;
    while (c.i >= 0)
    {
        stack_a[c.i + 1] = stack_a[c.i];
        c.i--;
    }
    stack_a[0] = stack_b[0];
    c.size_a++;
    c.size_b--;
    c.j = 1;
    while (c.j <= c.size_b)
    {
        stack_b[c.j - 1] = stack_b[c.j];
        c.j++;
    }
    ft_putstr_fd("pa\n", 1);
}

void    ft_pb(int *stack_a, int *stack_b)
{
    s_count c;

    c.j = c.size_b;
    while (c.j >= 0)
    {
        stack_b[c.j + 1] = stack_b[c.j];
        c.j--;
    }
    stack_b[0] = stack_a[0];
    c.size_a--;
    c.size_b++;
    c.i = 1;
    while (c.i <= c.size_a)
    {
        stack_b[c.i - 1] = stack_b[c.i];
        c.i++;
    }
    ft_putstr_fd("pb\n", 1);
}