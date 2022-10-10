/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:58 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/28 10:55:43 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     main(int ac, char **av)
{
    int *res_num;
    int len;

    error_check(ac, av);
    len = ft_ma_count(av);
    res_num = ft_pushint(av, len);
    check_dup(res_num, len);
    ft_sort(res_num, len);
/*
    int i = 0;
    while (i < len)
    {
        printf("res_num[%d] ===> [%d]\n", i, res_num[i]);
        i++;
    }
*/
    free(res_num);
    return (0);
}