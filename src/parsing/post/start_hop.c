/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_hop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 14:00:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int	MAX_HOP;

int	pp_start_hop(void)
{
	t_opt	*start_hop;
	int		value;

	start_hop = ft_optget("start-hop");
	if (!start_hop || !start_hop->value)
		return (1);
	value = ft_atoi(start_hop->value->value);
	if (value <= 0)
	{
		ft_perr("start-hop value too low. Defaulting to 1\n");
		value = 1;
	}
	if (value > MAX_HOP)
	{
		ft_perr("start-hop value too high. Defaulting to %d\n", MAX_HOP);
		value = MAX_HOP;
	}
	return (value);
}
