/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:30:44 by marvin            #+#    #+#             */
/*   Updated: 2022/10/02 19:30:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int     check_sort(int  *res_num, int len)
{
    int     i;
    int     check;

    i = 0;
    check = 1;
    while (i < len - 1)
    {
        if (res_num[i] < res_num[i + 1])
            check++;
        i++;
    }
    if (check == len)
        return (0);
    return (1);
}

void    ft_sort(int *res_num, int len)
{
/*
    printf("=====> hi <===== \n");

int a1 = 0;
while (a1 < len)
{
    printf(" in sort stack_a[%d] ===> [%d]\n", a1, res_num[a1]);
    a1++;
}
printf("\n");
*/
    if (check_sort(res_num, len) == 0)
        return ;
    if (len == 2)
    {
        if (res_num[0] > res_num[1])
            ft_sa(res_num, len, 0);
    }
    if (len == 3)
       ft_3_sort(res_num, len);
    if (len >= 4 && len <= 5)
       ft_5_sort(res_num, len);
    if (len >= 6 && len <= 100)
        ft_100_sort(res_num, len);
    if (len >= 101)
        ft_500_sort(res_num, len);
}