/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universe_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:09:36 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/14 14:01:55 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    ft_print(int *stack_a, int *stack_b, s_count *c)
{
    int h = 0;
    while (h < c->size_a)
    {
        printf(" ======== A[%d] ===> [%d]\n", h, stack_a[h]);
        h++;
    }
    h = 0;
    while (h < c->size_b)
    {
        printf(" ====== B[%d] ===> [%d]\n", h, stack_b[h]);
        h++;
    }/*
    int k = 0;
    while (k < 10)
    {
        printf("++++++ tmp ++++++ tmp[%d] ====> [%d]\n", k, c->tmp[k]);
        k++;
    }*/ 
    printf("\n");
}

void    ft_btoa_uni(int *stack_a, int *stack_b, s_count *c)
{
    s_count this;
    
    this.j = 0;
    while (c->size_b > 0)
                ft_pa(stack_a, stack_b, c);
}

void    ft_atob_uni(int *stack_a, int *stack_b, s_count *c)
{
    s_count this;
    
    this.j = 0;
    while (c->size_a > 0)
    {
        if (stack_a[0] == c->tmp[this.j])
        {
            ft_pb(stack_a, stack_b, c);
            this.j++;
        }
        else
            ft_ra(stack_a, c->size_a, 0);
    }
}

int     ft_universe(int *res_num, int len)
{
    s_count c;
    int *stack_b;
    
    c.size_b = 0;
    c.size_a = len;
    stack_b = (int *)malloc(sizeof(int) * len);
    c.tmp = ft_setindex_minmax(res_num, len);
    ft_atob_uni(res_num, stack_b, &c);
    ft_btoa_uni(res_num, stack_b, &c);
    free(c.tmp);
    free(stack_b);
    return (0);
}
