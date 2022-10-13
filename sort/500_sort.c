/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:29 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/13 17:01:16 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int     ft_500_sort(int *res_num, int len)
{
    s_count c;
    int *stack_b;

    c.size_b = 0;
    c.size_a = len;
    c.fd = len;
    c.i = len / 10;
    c.num1 = len - (len / 10);
    stack_b = (int *)malloc(sizeof(int) * len);
    c.tmp = ft_setindex_minmax(res_num, len);
    c.mid_chunk = 25;
    while (c.fd - c.i >= 0)
    {
        ft_set_chunk(res_num, len, stack_b, &c);
        if (c.fd == 100)
        {
            c.num1 -= 45;
            c.mid_chunk += 32;
        }
        else
        {
            c.num1 -= 50;
            c.mid_chunk += 50;
        }
        c.fd -= c.i;
    }
    ft_sort(res_num, c.size_a);
    ft_backtoa(res_num, stack_b, &c);
    free(c.tmp);
    free(stack_b);
    return (0);
}