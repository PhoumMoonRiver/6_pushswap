/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:34:14 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 10:16:19 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rra(int *stack_a, int len, int sec)
{
	t_c	c;

	if (len == 1)
		exit(0);
	c.num1 = stack_a[len - 1];
	while (len > 0)
	{
		stack_a[len] = stack_a[len - 1];
		len--;
	}
	stack_a[0] = c.num1;
	if (sec == 0)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(int *stack_b, int len, int sec)
{
	t_c	c;

	if (len == 1)
		exit(0);
	c.num1 = stack_b[len - 1];
	while (len > 0)
	{
		stack_b[len] = stack_b[len - 1];
		len--;
	}
	stack_b[0] = c.num1;
	if (sec == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(int *stack_a, int *stack_b, t_c *c, int sec)
{
	ft_rra(stack_a, c->size_a, 1);
	ft_rrb(stack_b, c->size_b, 1);
	if (sec == 0)
		ft_putstr_fd("rrr\n", 1);
}
