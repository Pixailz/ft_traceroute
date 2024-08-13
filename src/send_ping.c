/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:34:50 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 10:51:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int		SOCKET_SEND;
extern t_int4	TARGET_IP;

t_ts			LAST_SENDED;

t_bool	send_ping(t_packet pack)
{
	long			ret;
	struct sockaddr	dst;

	dst = ft_ltoaddr(TARGET_IP);
	ret = sendto(SOCKET_SEND, pack.data, PACK_LEN_IP + PACK_LEN_UDP, 0, &dst, \
																sizeof(dst));
	if (ret == -1)
		ft_perr("sendto");
	LAST_SENDED = ft_get_ts();
	return (FALSE);
}
