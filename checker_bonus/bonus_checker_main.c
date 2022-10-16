/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:21:54 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 11:41:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_sort_check(int *stack_a, t_c *c)
{
	int	i;

	i = 0;
	while (i < c->size_a)
	{
		if (c->tmp[i] == stack_a[i])
			i++;
		else
		{
			i = -1;
			return (i);
		}
	}
	return (i);
}

int	ft_cmp(char *instruc, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(instruc);
	while (i < len)
	{
		if (instruc[i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_doinstr(int *stack_a, int *stack_b, t_c *c, char *instruc)
{
	if (ft_cmp(instruc, "sa\n") == 0)
		ft_sa(stack_a, c->size_a, 1);
	else if (ft_cmp(instruc, "sb\n") == 0)
		ft_sb(stack_b, c->size_b, 1);
	else if (ft_cmp(instruc, "ss\n") == 0)
		ft_ss(stack_a, stack_b, c, 1);
	else if (ft_cmp(instruc, "ra\n") == 0)
		ft_ra(stack_a, c->size_a, 1);
	else if (ft_cmp(instruc, "rb\n") == 0)
		ft_rb(stack_b, c->size_b, 1);
	else if (ft_cmp(instruc, "rr\n") == 0)
		ft_rr(stack_a, stack_b, c, 1);
	else if (ft_cmp(instruc, "rra\n") == 0)
		ft_rra(stack_a, c->size_a, 1);
	else if (ft_cmp(instruc, "rrb\n") == 0)
		ft_rrb(stack_b, c->size_b, 1);
	else if (ft_cmp(instruc, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b, c, 1);
	else if (ft_cmp(instruc, "pa\n") == 0)
		ft_pa(stack_a, stack_b, c, 1);
	else if (ft_cmp(instruc, "pb\n") == 0)
		ft_pb(stack_a, stack_b, c, 1);
	else
		ft_doinstr_err();
}

int	main(int ac, char **av)
{
	t_c		c;
	int		*stack_b;
	int		*res_num;
	int		len;

	c.size_b = 0;
	error_check(ac, av);
	len = ft_ma_count(av);
	c.size_a = len;
	res_num = ft_pushint(av, len);
	check_dup(res_num, len);
	c.tmp = ft_setindex_minmax(res_num, len);
	stack_b = (int *)malloc(sizeof(int) * len);
	ft_check_next_line(res_num, stack_b, &c);
	free(res_num);
	free(stack_b);
	return (0);
}
