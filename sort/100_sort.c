/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:14:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/11 21:50:33 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    ft_set_chunk_stack_b(int *stack_b, s_count *c)
{
    if (stack_b[0] <= c->mid_chunk && c->size_b > 1)
        ft_rb(stack_b, c->size_b, 0);
}

void    ft_set_chunk(int *stack_a, int len, int *stack_b, s_count *c)
{
    s_count this;

    this.i = 0;
    this.k = 0;
    this.num2 = 0;
    this.num1 = len - (len / 5);
    while (this.k < (len / 5))
    {
        this.j = 0;
        while (this.j <= c->size_a && this.k < (len / 5))
        {
            if (c->size_a == 5)
                return ;
            else if (stack_a[this.j] <= c->tmp[len - c->num1 - 1])
            {
                if (stack_a[this.j] >= c->tmp[95])
                    ft_ra(stack_a, c->size_a, 1);
                else if (this.j == 0)
                {
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                }
                else if (this.j >= (c->size_a / 2) - 1 && this.j != 0)
                {
                    this.num2 = c->size_a - this.j;
                    while (this.num2 > 0 )
                    {
                        ft_rra(stack_a, c->size_a, 1);
                        this.num2--;
                    }
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                }
                else
                {
                    this.num2 = this.j;
                    while (this.num2 > 0)
                    {
                        ft_ra(stack_a, c->size_a, 1);
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
        c.mid_chunk += 20;
        c.num1 -= 20;
        c.fd -= c.i;
    }
/*
int b = 0;
while (b < 100)
{
    printf("----- B ----- stack_b[%d] ===> [%d]\n", b, stack_b[b]);
    b++;
}
printf("\n");
*/
    ft_sort(res_num, c.size_a);
/*
int s = 0;
while (s < 5)
{
    printf("----- A ----- res_num[%d] ===> [%d]\n", s, res_num[s]);
    s++;
}
printf("\n");
*/
printf("sizeof ++ c.size_a ++ [%d]\n", c.size_a);
printf("sizeof ++ c.size_b ++ [%d]\n", c.size_b);

    return (0);
}