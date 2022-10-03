/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:56:01 by marvin            #+#    #+#             */
/*   Updated: 2022/10/02 19:56:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void     ft_3_sort(int *res_num, int len)
{
    int i;

    while (check_sort(res_num, len) == 1)
    {
        if (res_num[0] > res_num[1] && res_num[0] > res_num[2])
        {
            ft_ra(res_num, len, 0);
            i = 0;
            while (i < len)
            {
                printf("ra[%d] ==> [%d]\n", i, res_num[i]);
                i++;
            }       
        }
        if (res_num[0] > res_num[1])
        {
            ft_sa(res_num, len, 0);
            i = 0;
            while (i < len)
            {
                printf("sa[%d] ==> [%d]\n", i, res_num[i]);
                i++;
            }
        }
        if (res_num[0] < res_num[1] && (res_num[0] > res_num[2] || res_num[1] > res_num[2]))
        {
            ft_rra(res_num, len, 0);
            i = 0;
            while (i < len)
            {
                printf("rra[%d] ==> [%d]\n", i, res_num[i]);
                i++;
            }
        }
    }
}