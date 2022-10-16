/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universe_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:09:36 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 11:25:16 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_btoa_uni(int *stack_a, int *stack_b, t_c *c)
{
	t_c	this;

	this.j = 0;
	while (c->size_b > 0)
		ft_pa(stack_a, stack_b, c, 0);
}

void	ft_atob_uni(int *stack_a, int *stack_b, t_c *c)
{
	t_c	this;

	this.j = 0;
	while (c->size_a > 0)
	{
		if (stack_a[0] == c->tmp[this.j])
		{
			ft_pb(stack_a, stack_b, c, 0);
			this.j++;
		}
		else
			ft_ra(stack_a, c->size_a, 0);
	}
}

int	ft_universe(int *res_num, int len)
{
	t_c	c;
	int	*stack_b;

	c.size_b = 0;
	c.size_a = len;
	stack_b = (int *)malloc(sizeof(int) * len);
	c.tmp = ft_setindex_minmax(res_num, len);
	ft_atob_uni(res_num, stack_b, &c);
	ft_btoa_uni(res_num, stack_b, &c);
	free(c.tmp);
	free(stack_b);
	return (0);
}
