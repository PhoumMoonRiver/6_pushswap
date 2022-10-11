/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:14:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/11 12:33:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    ft_set_chunk(int *stack_a, int len, int *stack_b, s_count *c)
{
    s_count this;
    int *tmp;

    this.i = 0;
    this.j = 1;
    this.k = 0;
    this.num1 = len - 20;
    this.num2 = 0;
    tmp = ft_setindex_minmax(stack_a, len);

    while (this.k < (len - this.num1))
    {
        this.j = 1;
        while (this.j < len && this.k < (len - this.num1))
        {
            if (stack_a[0] < tmp[len - this.num1])
            {
printf("stack_a 1 [0] ==> [%d]\n", stack_a[0]);
printf("stack_a 1 [1] ==> [%d]\n", stack_a[1]);
printf("stack_a 1 [2] ==> [%d]\n", stack_a[2]);
                    ft_pb(stack_a, stack_b, c);
                    this.k++;
                    c->num1--;
            }
            else if (stack_a[this.j] < tmp[len - this.num1])
            {
                this.num2 = this.j;
                if (this.j >= (c->num1 / 2) - 1)
                {
                    while (this.num2 > 0)
                    {
                        ft_rra(stack_a, c->num1, 1);
                        this.num2--;
                    }
printf("stack_a 2 [0] ==> [%d]\n", stack_a[0]);
printf("stack_a 2 [1] ==> [%d]\n", stack_a[1]);
printf("stack_a 2 [2] ==> [%d]\n", stack_a[2]);
                }
                else
                {
                    while (this.num2 > 0)
                    {
                        ft_ra(stack_a, c->num1, 1);
                        this.num2--;
                    }
printf("stack_a 3 [0] ==> [%d]\n", stack_a[0]);
printf("stack_a 3 [1] ==> [%d]\n", stack_a[1]);
printf("stack_a 3 [2] ==> [%d]\n", stack_a[2]);
                }
                ft_pb(stack_a, stack_b, c);
                c->num1--;
                this.k++;
            }
            this.j++;
        }
    }
}


int     ft_100_sort(int *res_num, int len)
{
    s_count c;
    int *stack_b;
    int *tmp;

    c.size_b = 0;
    c.size_a = len;
    c.num1 = len;
    stack_b = (int *)malloc(sizeof(int) * len);
    tmp = ft_setindex_minmax(res_num, len);
    ft_set_chunk(res_num, len, stack_b, &c);
    
    printf("sizeof ++ c.size_a ++ [%d]\n", c.size_a);
    printf("sizeof ++ c.size_b ++ [%d]\n", c.size_b);
    return (0);
}