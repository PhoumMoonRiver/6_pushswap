/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:43:19 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 11:00:55 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*ft_pushint(char **av, int len)
{
	t_c		c;
	int		*tem;
	char	**res_split;

	c.fd = 1;
	c.j = 0;
	tem = malloc(sizeof(int) * (len + 1));
	if (!tem)
		return (0);
	while (av[c.fd])
	{
		res_split = ft_split(av[c.fd], 32);
		c.num1 = 0;
		while (res_split[c.num1])
			tem[c.j++] = ft_atoi(res_split[c.num1++]);
		c.fd++;
		ft_free2d(res_split);
	}
	if (len <= 1)
	{
		if (tem)
			free(tem);
		exit (0);
	}
	return (tem);
}

int	ft_ma_count(char **av)
{
	t_c		c;
	char	**res_split;

	c.fd = 1;
	c.num2 = 0;
	while (av[c.fd])
	{
		res_split = ft_split(av[c.fd], 32);
		c.i = 0;
		while (res_split[c.i])
			c.i++;
		ft_free2d(res_split);
		c.num2 += c.i;
		c.fd++;
	}
	return (c.num2);
}
