/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:43:56 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 09:37:24 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    check_dup(int *res_num)
{
    s_count c;
    
    c.i = 0;
    while (res_num[c.i])
    {
        c.j = 1 + c.i;
        while (res_num[c.j])
        {
            if(res_num[c.i] == res_num[c.j])
            {
                ft_putstr_fd("Error\n", 2);
                exit(1);
            }
            c.j++; 
        }
        c.i++;
    }
}

void    check_num(char **av)
{
    size_t  fd;
    size_t  sd;

    fd = 1;
    while (av[fd])
    {
        sd = 0;
        while (av[fd][sd])
        {
            if (av[fd][0] == '-')
                sd++;
            if ((av[fd][sd] >= '0' && av[fd][sd] <= '9') || av[fd][sd] == 32)
                sd++;
            else
            {
                ft_putstr_fd("Error\n", 2);
                exit(1);
            }
        }
        fd++;
    }
}

void    error_check(int ac, char **av)
{
    if (ac <= 2)
        exit(1);
    check_num(av);
}

/*
 1. ตรวจสอบข้อมูลที่ส่งเข้ามาหากมีเพียงจำนวนเดียว โปรแกรมต้องแสดงผลเป็น "error" ออกมาเพราะ ไม่สามารถจัดเรียงได้
 2. ตรวจสอบการส่งข้อมูล int ที่ถูกต้องคือ {1, -1} เท่านั้น ไม่สามารถรับค่า ตัวอักษร หรือ --1 , 1-- , +1
 3. ตรวจสอบว่าข้อมูลที่ส่งเข้ามานั้น ซ้ำ กันหรือไม่ หากซ้ำกันให้แสดงผล "error"
 4. ตรวจสอบว่าค่าข้อมูลเกิน int หรือไม่ หากเกินให้แสดงผล "error"
*/