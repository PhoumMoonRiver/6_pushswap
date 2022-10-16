/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:13:58 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 10:27:53 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	int	*res_num;
	int	len;

	error_check(ac, av);
	len = ft_ma_count(av);
	res_num = ft_pushint(av, len);
	check_dup(res_num, len);
	ft_sort(res_num, len);
	free(res_num);
	return (0);
}
