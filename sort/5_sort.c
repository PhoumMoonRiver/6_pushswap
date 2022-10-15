/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:07:42 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 11:59:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_set_push(t_c *c, int *res_num, int *stack_b, t_c *this)
{
	if (c->i >= 2 && c->i <= 4)
	{
		if (c->i == 2)
		{
			while (this->num1-- > 0)
				ft_ra(res_num, c->num1, 0);
		}
		else
		{
			while (this->num1++ < c->num1)
				ft_rra(res_num, c->num1, 0);
		}
		ft_pb(res_num, stack_b, c);
	}
}

void	ft_set_5_sort(t_c *c, int *res_num, int *tmp, int *stack_b)
{
	t_c	this;

	this.num1 = 0;
	if (res_num[c->i] < tmp[2])
	{
		this.num1 = c->i;
		if (c->i == 0)
			ft_pb(res_num, stack_b, c);
		else if (c->i == 1)
		{
			ft_sa(res_num, c->num1, 0);
			ft_pb(res_num, stack_b, c);
		}
		ft_set_push(c, res_num, stack_b, &this);
		c->num1--;
		c->j++;
	}
	return ;
}

void	ft_gotoset(t_c *c, int *res_num, int *tmp, int *stack_b)
{
	while (c->j < 2)
	{
		c->i = 0;
		while (c->i < c->num1)
		{
			ft_set_5_sort(c, res_num, tmp, stack_b);
			c->i++;
		}
	}
}

int	ft_5_sort(int *res_num, int len)
{
	t_c	c;
	int	*stack_b;
	int	*tmp;

	c.j = 0;
	c.size_b = 0;
	c.size_a = len;
	c.num1 = len;
	stack_b = (int *)malloc(sizeof(int) * len);
	tmp = ft_setindex_minmax(res_num, len);
	ft_gotoset(&c, res_num, tmp, stack_b);
	free(tmp);
	ft_sort(res_num, c.size_a);
	if (stack_b[1] > stack_b[0])
		ft_sb(stack_b, len, 0);
	while (c.size_b > 0)
		ft_pa(res_num, stack_b, &c);
	free (stack_b);
	return (0);
}
