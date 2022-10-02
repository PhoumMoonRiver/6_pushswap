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