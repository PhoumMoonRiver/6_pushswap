/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:07:42 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/06 15:07:42 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int     ft_5_sort(int *res_num, int len)
{
    s_count c;
    int *tmp;
    int *stack_b;

    c.i = 0;
    c.j = 0;
    c.num1 = 0;
    c.size_b = 0;
    c.size_a = len;
    tmp = ft_setindex_minmax(res_num, len);
    stack_b = (int *)malloc(sizeof(int) * len);
    while (c.j < 2)
    {
        c.i = 0;
        while (c.i < len)
        {
            if (res_num[c.i] < tmp[2])
            {
                c.num1 = c.i;
                if (c.i == 0)
                    ft_pb(res_num, stack_b, &c);
                else if (c.i == 1)
                {
                    ft_sa(res_num, len, 0);
                    ft_pb(res_num, stack_b, &c);
                }
                else if (c.i >= 2 && c.i <= 4)
                {
                    if (c.i == 2)
                    {
                        while (c.num1-- > 0)
                            ft_ra(res_num, len, 0);
                    }
                    else
                    {
                        while (c.num1++ < len)
                            ft_rra(res_num, len, 0);
                    }
                    ft_pb(res_num, stack_b, &c); 
                }
                len--;
                c.j++;
            }
            c.i++;
        }
    }
    ft_sort(res_num, c.size_a);
    if (stack_b[1] > stack_b[0])
        ft_sb(stack_b, len, 0);
    while (c.size_b > 0)
        ft_pa(res_num, stack_b, &c);
    free(tmp);
    free(stack_b);
    return(0); 
}