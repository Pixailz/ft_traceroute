/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_hop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:55:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:29:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	MAX_HOP = TRT_MAX_HOP;

void	pp_max_hop(void)
{
	t_opt	*max_hop;
	int		value;
	int		retv;

	max_hop = ft_optget("max-hop");
	if (!max_hop || !max_hop->value)
		return ;
	value = ft_patoi(max_hop->value->value, &retv);
	if (retv || value <= 0)
	{
		ft_perr("Invalid max-hop value. Defaulting to %d\n", TRT_MAX_HOP);
		MAX_HOP = TRT_MAX_HOP;
		return ;
	}
	MAX_HOP = value;
}
