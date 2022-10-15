/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:43:13 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 10:15:37 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_ra(int *stack_a, int len, int sec)
{
	t_c	c;

	if (len == 1)
		exit(0);
	c.i = 1;
	c.num2 = len;
	c.num1 = stack_a[0];
	while (len > 0)
	{
		stack_a[c.i - 1] = stack_a[c.i];
		c.i++;
		len--;
	}
	stack_a[c.num2 - 1] = c.num1;
	if (sec == 0)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int *stack_b, int len, int sec)
{
	t_c	c;

	if (len == 1)
		exit(0);
	c.i = 1;
	c.num2 = len;
	c.num1 = stack_b[0];
	while (len > 0)
	{
		stack_b[c.i - 1] = stack_b[c.i];
		c.i++;
		len--;
	}
	stack_b[c.num2 - 1] = c.num1;
	if (sec == 0)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	ft_ra(stack_a, len_a, 1);
	ft_rb(stack_b, len_b, 1);
	ft_putstr_fd("rr\n", 1);
}
