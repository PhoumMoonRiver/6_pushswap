/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:14:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/13 07:25:21 by njerasea         ###   ########.fr       */
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
    }
 /*   int k = 0;
    while (k < 100)
    {
        printf("++++++ tmp ++++++ tmp[%d] ====> [%d]\n", k, c->tmp[k]);
        k++;
    } */
    printf("\n");
}

void    ft_backtoa(int *stack_a, int *stack_b, s_count *c)
{
    s_count this;

    this.j = c->size_b - 1;
    this.num2 = 0;
    while (this.j >= 0)
    {
        this.i = 0;
        while (this.i < c->size_b && this.j >= 0)
        {
            if (stack_b[this.i] == c->tmp[this.j])
            {
                if (this.i == 0)
                {
                    ft_pa(stack_a, stack_b, c);
                    this.j--;
                }
                else if (this.i >= (c->size_b / 2) - 1 && this.i != 0)
                {
                    this.num2 = c->size_b - this.i;
                    while (this.num2 > 0 )
                    {
                        ft_rrb(stack_b, c->size_b, 0);
                        this.num2--;
                    }
                    ft_pa(stack_a, stack_b, c);
                    this.j--;
                }
                else
                {
                    this.num2 = this.i;
                    while (this.num2 > 0)
                    {
                        ft_rb(stack_b, c->size_b, 0);
                        this.num2--;
                    }
                    ft_pa(stack_a, stack_b, c);
                    this.j--;
                }
            }

            this.i++;
        }
    } 
}

void    ft_set_chunk_stack_b(int *stack_a, int *stack_b, s_count *c, int len)
{
    if (stack_a[0] > c->tmp[(len - c->num1) - 1] && stack_b[0] <= c->tmp[c->mid_chunk - 1] 
        && c->size_b > 1)
        ft_rr(stack_a, stack_b, c->size_a, c->size_b);
    else if (stack_b[0] <= c->tmp[c->mid_chunk - 1] && c->size_b > 1)
        ft_rb(stack_b, c->size_b, 0);
}

void    ft_set_chunk(int *stack_a, int len, int *stack_b, s_count *c)
{
    s_count this;

    this.i = 0;
    this.k = 0;
    while (this.k < (len / 5))
    {
        if (c->size_a == 5)
            return ;
        this.j = 0;
        this.size_a = c->size_a - 1;
        while (this.j < c->size_a)
        {
            if (stack_a[this.j] <= c->tmp[(len - c->num1) - 1])
                break ;
            this.j++;
        }
        while (this.size_a > 0)
        {
            if (stack_a[this.size_a] <= c->tmp[(len - c->num1) - 1])
                break ;
            this.size_a--;
        }
        if (this.j > (c->size_a - this.size_a))
        {
            this.keep = stack_a[this.size_a];
            while (stack_a[0] != this.keep)
                ft_rra(stack_a, c->size_a, 0);
            ft_pb(stack_a, stack_b, c);
            this.k++;
        }
        else
        {
            this.keep = stack_a[this.j];
            while (stack_a[0] != this.keep)
                ft_ra(stack_a, c->size_a, 0);
            ft_pb(stack_a, stack_b, c);
            this.k++;
        }
        ft_set_chunk_stack_b(stack_a, stack_b, c, len);
    }
}

int     ft_100_sort(int *res_num, int len)
{
    s_count c;
    int *stack_b;

    c.size_b = 0;
    c.size_a = len;
    c.fd = len;
    c.i = len / 5;
    c.num1 = len - (len / 5);
    stack_b = (int *)malloc(sizeof(int) * len);
    c.tmp = ft_setindex_minmax(res_num, len);
    c.mid_chunk = 10;
    while (c.fd - c.i >= 0)
    {
        ft_set_chunk(res_num, len, stack_b, &c);
        if (c.fd == 40)
        {
            c.num1 -= 15;
            c.mid_chunk += 17;
        }
        else
        {
            c.num1 -= 20;
            c.mid_chunk += 20;
        }
        c.fd -= c.i;
    }
    ft_sort(res_num, c.size_a);
    ft_backtoa(res_num, stack_b, &c);
    free(c.tmp);
    free(stack_b);
    return (0);
}