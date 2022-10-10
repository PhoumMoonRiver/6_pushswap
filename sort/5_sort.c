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
            if (res_num[c.i] == tmp[c.j])
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
/*
int a3 = 0;
while (a3 < len)
{
    printf("{{{{ res_num }}}}[%d] ===> [%d]\n", a3, res_num[a3]);
    a3++;
}
printf("\n");
*/
            }
            c.i++;
        }
    }
/*       
printf("This is size of b ===> [%d]\n", c.size_b);
printf("This is size of a ===> [%d]\n", c.size_a);
printf("\n");

int i = 0;
while (i < c.size_b)
{
    printf("-------]stack_b[%d] ===> [%d]\n", i, stack_b[i]);
    i++;
}
printf("\n");
*/
    ft_sort(res_num, c.size_a);
/*
int a1 = 0;
while (a1 < c.size_a)
{
    printf("sort ---> stack_a[%d] ===> [%d]\n", a1, res_num[a1]);
    a1++;
}
printf("\n");
*/
    if (stack_b[1] > stack_b[0])
        ft_sb(stack_b, len, 0);
/*
int i1 = 0;
while (i1 < c.size_b)
{
    printf("[[[[ . sort ---> stack_b[%d] ===> [%d]\n", i1, stack_b[i1]);
    i1++;
}
printf("\n");
*/
    while (c.size_b > 0)
        ft_pa(res_num, stack_b, &c);
    free(tmp);
    free(stack_b);
    return(0); 
}