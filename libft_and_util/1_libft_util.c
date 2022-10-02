/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_libft_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:49:13 by njerasea          #+#    #+#             */
/*   Updated: 2022/09/27 09:15:50 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	long int			res;
	int			sign;
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN)
	{
    	ft_putstr_fd("Error\n", 2);
        exit(1); 
    }
	return (res * sign);
}

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}