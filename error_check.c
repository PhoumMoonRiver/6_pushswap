/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:43:56 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 10:56:51 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_dup(int *res_num, int len)
{
	t_c	c;

	c.i = 0;
	c.j = 0;
	while (c.i < len)
	{
		c.j = 1 + c.i;
		while (c.j < len)
		{
			if (res_num[c.i] == res_num[c.j])
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			c.j++;
		}
		c.i++;
	}
}

void	check_num(char **av)
{
	size_t	fd;
	size_t	sd;

	fd = 1;
	while (av[fd])
	{
		sd = 0;
		while (av[fd][sd])
		{
			if ((av[fd][sd] == '-' && sd == 0 && (av[fd][sd + 1] >= '0' 
				&& av[fd][sd + 1] <= '9')) || (av[fd][sd] == '-'
				&& av[fd][sd - 1] == 32) || ((av[fd][sd] >= '0'
				&& av[fd][sd] <= '9') || av[fd][sd] == 32))
				sd++;
			else
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
		}
		fd++;
	}
}

void	error_check(int ac, char **av)
{
	t_c	this;

	this.fd = 1;
	if (ac == 1)
		exit(0);
	while (av[this.fd])
	{
		if (av[this.fd][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		this.fd++;
	}
	check_num(av);
}
