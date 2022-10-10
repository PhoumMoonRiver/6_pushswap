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

void    ft_set_5_sort(s_count *c, int *res_num, int *tmp, int *stack_b)
{
    s_count this;
    
    this.num1 = 0;
    if (res_num[c->i] < tmp[2])
    {
        this.num1 = c->i;
        if (c->i == 0)
            ft_pb(res_num, stack_b, c);
        else if (c->i == 1)
        {
            ft_sa(res_num, c->num1, 0);
            ft_pb(res_num, stack_b, c);
        }
        else if (c->i >= 2 && c->i <= 4)
        {
            if (c->i == 2)
            {
                while (this.num1-- > 0)
                    ft_ra(res_num, c->num1, 0);
            }
            else
            {
                while (this.num1++ < c->num1)
                    ft_rra(res_num, c->num1, 0);
            }
            ft_pb(res_num, stack_b, c); 
        }
        c->num1--;
        c->j++;
    }
    return ;
}

int     ft_5_sort(int *res_num, int len)
{
    s_count c;
    int *stack_b;
    int *tmp;

    c.j = 0;
    c.size_b = 0;
    c.size_a = len;
    c.num1 = len;
    stack_b = (int *)malloc(sizeof(int) * len);
    tmp = ft_setindex_minmax(res_num, len);
    while (c.j < 2)
    {
        c.i = 0;
        while (c.i < c.num1)
        {
            ft_set_5_sort(&c, res_num, tmp, stack_b);
            c.i++;
        }
    }
    free(tmp);
    ft_sort(res_num, c.size_a);
    if (stack_b[1] > stack_b[0])
        ft_sb(stack_b, len, 0);
    while (c.size_b > 0)
        ft_pa(res_num, stack_b, &c);
    free(stack_b);
    return(0); 
}