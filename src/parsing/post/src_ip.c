/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_ip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:52:37 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:05:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_int4	SRC_IP = 0;

void	pp_src_ip(void)
{
	t_opt	*src_ip;

	src_ip = ft_optget("source-ip");
	if (!src_ip || !src_ip->value)
		return ;
	SRC_IP = ft_ipstr(src_ip->value->value);
	if (!SRC_IP)
		ft_perr("source-ip wrong value\n");
}
