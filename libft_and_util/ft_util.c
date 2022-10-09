/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:15:18 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 10:03:11 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void ft_free2d(char **free2)
{
	int	i;

	i = 0;
	if (!free2 || !free2[i])
		return ;
	while (free2[i])
		free(free2[i++]);
	free(free2);
}

int     *ft_setindex_minmax(int *res_num, int len)
{
    int *a;
    s_count c;

    c.j = 0;
    c.num1 = 0;
    c.num2 = 0;
    a = (int *)malloc(sizeof(int) * len);
    while (c.j < len)
    {
        c.i = 0;
        c.fd = len;
        while (a[c.i] < res_num[c.j] && c.fd--)
        {
            if (c.i == c.j)
                a[c.i] = res_num[c.j];
            c.i++;
        }
        if (a[c.i] > res_num[c.j])
        {
            c.num2 = c.j;
            while (c.num2 - c.i > 0)
            {
                a[c.num2] = a[c.num2 - 1];
                c.num2--;
            }
            a[c.i] = res_num[c.j];
        }
        c.j++;   
	}
	return(a);
}