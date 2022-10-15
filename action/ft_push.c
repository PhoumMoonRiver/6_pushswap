/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:03:06 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 10:15:11 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_pa(int *stack_a, int *stack_b, t_c *c, int sec)
{
	t_c	this;

	this.i = c->size_a;
	while (this.i >= 0)
	{
		stack_a[this.i + 1] = stack_a[this.i];
		this.i--;
	}
	stack_a[0] = stack_b[0];
	c->size_a++;
	c->size_b--;
	this.j = 1;
	while (this.j <= c->size_b)
	{
		stack_b[this.j - 1] = stack_b[this.j];
		this.j++;
	}
	if (sec == 0)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(int *stack_a, int *stack_b, t_c *c, int sec)
{
	t_c	this;

	this.j = c->size_b;
	while (this.j >= 0)
	{
		stack_b[this.j + 1] = stack_b[this.j];
		this.j--;
	}
	stack_b[0] = stack_a[0];
	c->size_a--;
	c->size_b++;
	this.i = 1;
	while (this.i <= c->size_a)
	{
		stack_a[this.i - 1] = stack_a[this.i];
		this.i++;
	}
	if (sec == 0)
		ft_putstr_fd("pb\n", 1);
}
