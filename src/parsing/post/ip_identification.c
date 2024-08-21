/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_identification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:13:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_uint16	IP_IDENT = TRT_IP_IDENT;

void pp_ip_identification(void)
{
	t_opt	*ip_ident;
	int		value;
	int		retv;

	ip_ident = ft_optget("ip-identification");
	if (!ip_ident || !ip_ident->value)
		return ;
	value = ft_patoi(ip_ident->value->value, &retv);
	if (retv)
	{
		ft_perr("ip_ident wrong value. Defaulting to %d\n", TRT_IP_IDENT);
		return ;
	}
	else if (IP_IDENT <= 0)
	{
		ft_perr("ip_ident value too low. Defaulting to %d\n", TRT_IP_IDENT);
		return ;
	}
	else if (IP_IDENT == 0xffff)
	{
		ft_perr("ip_ident value too high. Defaulting to %d\n", TRT_IP_IDENT);
		return ;
	}
	IP_IDENT = value;
}
