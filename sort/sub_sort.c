/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:01:32 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/15 12:27:15 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_set_round_100(t_c *c, int *res_num, int len, int *stack_b)
{
	while (c->fd - c->i >= 0)
	{
		ft_set_chunk(res_num, len, stack_b, c);
		if (c->fd == 40)
		{
			c->num1 -= 15;
			c->mid_chunk += 17;
		}
		else
		{
			c->num1 -= 20;
			c->mid_chunk += 20;
		}
		c->fd -= c->i;
	}
}

void	ft_set_pushtob(t_c *this, t_c *c, int *stack_a, int *stack_b)
{
	if (this->j > (c->size_a - this->size_a))
	{
		this->keep = stack_a[this->size_a];
		while (stack_a[0] != this->keep)
			ft_rra(stack_a, c->size_a, 0);
		ft_pb(stack_a, stack_b, c);
		this->k++;
	}
	else
	{
		this->keep = stack_a[this->j];
		while (stack_a[0] != this->keep)
			ft_ra(stack_a, c->size_a, 0);
		ft_pb(stack_a, stack_b, c);
		this->k++;
	}
}

void	ft_set_pushtoa(t_c *this, t_c *c, int *stack_a, int *stack_b)
{
	if (this->i >= (c->size_b / 2) - 1)
	{
		while (stack_b[0] != this->keep)
		{
			if (stack_b[0] == this->keep2)
				ft_pa(stack_a, stack_b, c);
			else
				ft_rrb(stack_b, c->size_b, 0);
		}
		ft_pa(stack_a, stack_b, c);
	}
	else
	{
		while (stack_b[0] != this->keep)
		{
			if (stack_b[0] == this->keep2)
				ft_pa(stack_a, stack_b, c);
			else
				ft_rb(stack_b, c->size_b, 0);
		}
		ft_pa(stack_a, stack_b, c);
	}
}
