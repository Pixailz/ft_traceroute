/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_hop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:55:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 13:55:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	pp_max_hop(void)
{
	t_opt	*max_hop;
	int		value;

	max_hop = ft_optget("max-hop");
	if (!max_hop || !max_hop->value)
		return (TRT_MAX_HOP);
	value = ft_atoi(max_hop->value->value);
	if (value <= 0)
	{
		ft_perr("Invalid max-hop value. Defaulting to %d\n", TRT_MAX_HOP);
		value = TRT_MAX_HOP;
	}
	return (value);
}
