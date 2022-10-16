/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:47:20 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 10:13:24 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_doinstr_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_check_next_line(int *res_num, int *stack_b, t_c *c)
{
	char	*instruc;

	while (1)
	{
		instruc = get_next_line(0);
		if (instruc == NULL)
			break ;
		ft_doinstr(res_num, stack_b, c, instruc);
		free(instruc);
	}
	if (ft_sort_check(res_num, c) == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}
