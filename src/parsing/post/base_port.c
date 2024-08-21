/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_port.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:18:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_uint16	BASE_PORT = TRT_BASE_PORT;

void	pp_base_port(void)
{
	t_opt	*opt;
	int		value;
	int		retv;

	opt = ft_optget("base-port");
	if (!opt || !opt->value)
		return ;
	value = ft_patoi(opt->value->value, &retv);
	if (retv || value > 0xffff)
	{
		ft_perr("base-port wrong value. Defaulting to %d\n", TRT_BASE_PORT);
		return ;
	}
	else if (value <= 0)
	{
		ft_perr("base-port value too low. Defaulting to 1\n");
		BASE_PORT = 1;
		return ;
	}
	BASE_PORT = value;
}
