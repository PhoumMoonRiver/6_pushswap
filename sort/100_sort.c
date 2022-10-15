/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:14:23 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 19:18:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_backtoa(int *stack_a, int *stack_b, t_c *c)
{
	t_c	this;

	this.num2 = 0;
	while (c->size_b > 0)
	{
		this.i = 0;
		while (this.i < c->size_b && c->size_b > 0)
		{
			if (stack_b[this.i] == c->tmp[c->size_b - 1])
			{
				this.keep = stack_b[this.i];
				this.keep2 = c->tmp[c->size_b - 2];
				ft_set_pushtoa(&this, c, stack_a, stack_b);
				if (stack_a[0] > stack_a[1])
					ft_sa(stack_a, c->size_a, 0);
			}
			this.i++;
		}
	}
}

void	ft_set_chunk_stack_b(int *stack_a, int *stack_b, t_c *c, int len)
{
	if (stack_a[0] > c->tmp[(len - c->num1) - 1] && stack_b[0]
		<= c->tmp[c->mid_chunk - 1] && c->size_b > 1)
		ft_rr(stack_a, stack_b, c, 0);
	else if (stack_b[0] <= c->tmp[c->mid_chunk - 1] && c->size_b > 1)
		ft_rb(stack_b, c->size_b, 0);
}

void	ft_set_chunk(int *stack_a, int len, int *stack_b, t_c *c)
{
	t_c	this;

	this.i = 0;
	this.k = 0;
	while (this.k < c->i)
	{
		if (c->size_a == 5)
			return ;
		this.j = 0;
		this.size_a = c->size_a - 1;
		while (this.j < c->size_a)
		{
			if (stack_a[this.j] <= c->tmp[(len - c->num1) - 1])
				break ;
			this.j++;
		}
		while (this.size_a > 0)
		{
			if (stack_a[this.size_a] <= c->tmp[(len - c->num1) - 1])
				break ;
			this.size_a--;
		}
		ft_set_pushtob(&this, c, stack_a, stack_b);
		ft_set_chunk_stack_b(stack_a, stack_b, c, len);
	}
}

int	ft_100_sort(int *res_num, int len)
{
	t_c	c;
	int	*stack_b;

	c.size_b = 0;
	c.size_a = len;
	c.fd = len;
	c.i = len / 5;
	c.num1 = len - (len / 5);
	stack_b = (int *)malloc(sizeof(int) * len);
	c.tmp = ft_setindex_minmax(res_num, len);
	c.mid_chunk = 10;
	ft_set_round_100(&c, res_num, len, stack_b);
	ft_sort(res_num, c.size_a);
	ft_backtoa(res_num, stack_b, &c);
	free(c.tmp);
	free(stack_b);
	return (0);
}
