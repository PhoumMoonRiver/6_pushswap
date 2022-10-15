/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:56:01 by marvin            #+#    #+#             */
/*   Updated: 2022/10/15 10:20:06 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_3_sort(int *res_num, int len)
{
	while (check_sort(res_num, len) == 1)
	{
		if (res_num[0] > res_num[1] && res_num[0] > res_num[2])
			ft_ra(res_num, len, 0);
		if (res_num[0] > res_num[1])
			ft_sa(res_num, len, 0);
		if (res_num[0] < res_num[1] && (res_num[0] > res_num[2]
				|| res_num[1] > res_num[2]))
			ft_rra(res_num, len, 0);
	}
}
