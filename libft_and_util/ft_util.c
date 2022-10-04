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

void ft_setindex_minmax(data *a, int *res_num, int len)
{
	s_count c;

	c.i = 0;
	while (c.i < len)
	{
		a[c.i].content = res_num[c.i];
printf("a.content ==> [%d]", a[c.i].content);
		c.i++;
	}
}