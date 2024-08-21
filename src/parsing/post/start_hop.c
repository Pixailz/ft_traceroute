/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_hop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:29:37 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int	MAX_HOP;
t_uint8	CURRENT_TTL = 1;

void	pp_start_hop(void)
{
	t_opt	*start_hop;
	int		value;
	int		retv;

	start_hop = ft_optget("start-hop");
	if (!start_hop || !start_hop->value)
		return ;
	value = ft_patoi(start_hop->value->value, &retv);
	if (retv)
	{
		ft_perr("start-hop wrong value. Defaulting to 1\n");
	}
	else if (value == 0)
	{
		ft_perr("start-hop value too low. Defaulting to 1\n");
	}
	else if (value > MAX_HOP)
	{
		ft_perr("start-hop value too high. Defaulting to %d\n", MAX_HOP);
		CURRENT_TTL = MAX_HOP;
	}
	CURRENT_TTL = value;
}
