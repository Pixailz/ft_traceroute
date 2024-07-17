/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_identification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 14:33:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int pp_ip_identification(void)
{
	t_opt	*ip_ident;
	int		value;

	ip_ident = ft_optget("ip-identification");
	if (!ip_ident || !ip_ident->value)
		return (TRT_IP_IDENT);
	ft_printf("ip_identification %s\n", ip_ident->value->value);
	value = ft_atoi(ip_ident->value->value);
	if (value <= 0)
	{
		ft_perr("ip_ident value too low. Defaulting to %d\n", TRT_IP_IDENT);
		value = TRT_IP_IDENT;
	}
	else if (value > 0xffff)
	{
		ft_perr("nb-prob value too high. Defaulting to %d\n", TRT_IP_IDENT);
		value = TRT_IP_IDENT;
	}
	return (value);
}
