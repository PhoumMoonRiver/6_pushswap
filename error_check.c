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

char    check_dup(int *res_num)
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
    free(res_num);
    return (0);
}

char    check_num(char **av)
{
    size_t  fd;
    size_t  sd;

    fd = 1;
    while (av[fd])
    {
        sd = 0;
        while (av[fd][sd])
        {
            if (av[fd][sd] == '-')
                sd++;
            if (av[fd][sd] >= '0' && av[fd][sd] <= '9')
                sd++;
            else
            {
                ft_putstr_fd("Error\n", 2);
                exit(1);
            }
        }
        fd++;
    }
    return (0);
}

char    error_check(int ac, char **av)
{
    if (ac == 1)
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    check_num(av);
//    check_dup(av);
    return (0);  
}