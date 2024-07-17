/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:25 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 13:54:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_int4		TARGET_IP = 0;

t_bool	pp_ip(char *target)
{
	if (!ft_strncmp(target, "0.0.0.0", 7))
	{
		TARGET_IP = 0;
		return (FALSE);
	}
	if (!ft_strncmp(target, "localhost", 9))
	{
		TARGET_IP = 0x7f000001;
		return (FALSE);
	}
	TARGET_IP = ft_ipstr(target);
	if (TARGET_IP)
		return (FALSE);
	TARGET_IP = ft_htoi4(target, FT_NULL);
	if (TARGET_IP)
		return (FALSE);
	ft_perr("%s: unknown host\n", PROG_NAME);
	return (TRUE);
}
