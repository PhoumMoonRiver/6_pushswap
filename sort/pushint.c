/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:43:19 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 10:06:16 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int     *ft_pushint(char **av, int len)
{
    s_count c;
    int    *tem;
    char    **res_split;

    c.fd = 1;
    c.j = 0;
    tem = malloc(sizeof(int) * (len));
    if (!tem)
        return (0);
    while (av[c.fd])
    {
        res_split = ft_split(av[c.fd], 32);
        c.num1 = 0;
        while (res_split[c.num1])
            tem[c.j++]   = ft_atoi(res_split[c.num1++]);
        c.fd++;
        ft_free2d(res_split);
    }
    return (tem);
}

int     ft_ma_count(char **av)
{
    s_count c;
    char    **res_split;
    
    c.fd = 1;
    c.num2 = 0;
    while (av[c.fd])
    {
        res_split = ft_split(av[c.fd], 32);
        c.i = 0;
        while (res_split[c.i])
            c.i++;
        c.num2 += c.i;
        c.fd++;
    }
    ft_free2d(res_split);
    return (c.num2);
}

/*
    1. ft_ma_count ==> ไว้สำหรับนับจำนวนข้อมูลที่ส่งเข้ามา เช่น {1 "1 2 3 5" -6} ==> ต้องนับได้ {6}
    2. ft_pushint ==> ไว้สำหรับเปลียนตัวอักษร ให้เป็นตัวเลข โดยใช้ atoi เข้ามาช่วย
*/