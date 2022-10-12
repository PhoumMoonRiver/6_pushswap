/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:14:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/12 21:39:43 by njerasea         ###   ########.fr       */
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
    int k = 0;
    while (k < 100)
    {
        printf("++++++ tmp ++++++ tmp[%d] ====> [%d]\n", k, c->tmp[k]);
        k++;
    }
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
////printf("tmp ===> [%d]\n",c->tmp[this.j]);
////printf("stack_b[%d] ===> [%d]\n", this.i ,stack_b[this.i]);
            if (stack_b[this.i] == c->tmp[this.j])
            {
////printf("+++++ HI +++++");
                if (this.i == 0)
                {
                    ft_pa(stack_a, stack_b, c);
//printf("stacK_a ===> [%d]\n", stack_a[0]);
//printf("stacK_b ===> [%d]\n", stack_b[0]);
//exit(0);
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
//printf("stacK_a ===> [%d]\n", stack_a[0]);
//printf("stacK_b ===> [%d]\n", stack_b[0]);
//exit(0);
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
//printf("stacK_a ===> [%d]\n", stack_a[0]);
//printf("stacK_b ===> [%d]\n", stack_b[0]);
//exit(0);
                    this.j--;
                }
            }

            this.i++;
        }
    } 
}

void    ft_set_chunk_stack_b(int *stack_b, s_count *c)
{
    if (stack_b[0] <= c->tmp[c->mid_chunk - 1] && c->size_b > 1)
        ft_rb(stack_b, c->size_b, 0);
}

void    ft_set_chunk(int *stack_a, int len, int *stack_b, s_count *c)
{
    s_count this;

    this.i = 0;
    this.k = 0;
    this.num1 = len - (len / 5);
    this.num2 = 0;
    while (this.k < (len / 5))
    {
        this.j = 0;
        while (this.j <= c->size_a && this.k < (len / 5))
        {
            if (c->size_a == 5)
                return ;
            if (stack_a[this.j] <= c->tmp[(len - c->num1) - 1])
            {
                if (this.j == 0)
                {
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                }
                else if (this.j >= (c->size_a / 2) - 1 && this.j != 0)
                {  

                    int  tmp = stack_a[this.j];
                    while (stack_a[0] != tmp)
                    {
                        ft_rra(stack_a, c->size_a, 0);
                    }
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                }
                else
                {
                    this.num2 = this.j;
                    while (this.num2 > 0)
                    {
                        ft_ra(stack_a, c->size_a, 0);
                        this.num2--;
                    }
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                }
                ft_set_chunk_stack_b(stack_b, c);
            }
            this.j++;
        }
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
        if (c.fd == 100)
            exit(0);
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
        //printf(" หลัง num1 => [[%d]\n", c.num1);
    }
//ft_print(res_num, stack_b, &c);
//exit (0);

    ft_sort(res_num, c.size_a);
    ft_backtoa(res_num, stack_b, &c);
/*
printf("sizeof ++ c.size_a ++ [%d]\n", c.size_a);
printf("sizeof ++ c.size_b ++ [%d]\n", c.size_b);
*/
    free(c.tmp);
    free(stack_b);
    return (0);
}