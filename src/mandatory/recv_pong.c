/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_pong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:53:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/12 18:28:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int SOCKET;

static t_bool	recv_echo_reply(t_packet *pong_pkt)
{
	long			ret;

	ret = recvfrom(
		SOCKET,					// SOCKET
		pong_pkt->data,			// BUFFER
		PACK_TOT_LEN_ICMP_TIME,	// LEN
		0,						// FLAG
		FT_NULL,				// SOCK ADDR FROM
		0						// SOCK ADDR FROM LEN
	);
	return (ret == -1);
}

static t_bool	check_reply(t_packet *pkt)
{
	t_iphdr					*pack_ip;
	t_icmphdr_time_exceed	*pack_icmp;

	pack_ip = ft_pkt_get_ip(pkt);
	pack_icmp = ft_pkt_get_icmp_time_exceed(pkt);

	if (pack_icmp->type == ICMP_TIME_EXCEEDED)
	{
		ft_putip_fd(ft_htonl(pack_ip->src_addr), 1);
		ft_printf(" Time Exceed\n");
		return (TRUE);
	}
	else if (	pack_icmp->type == ICMP_DEST_UNREACH &&
				pack_icmp->code == ICMP_PORT_UNREACH)
	{
		ft_putip_fd(ft_htonl(pack_ip->src_addr), 1);
		ft_printf(" Dest Reached\n");
		return (TRUE);
	}
	ft_printf("An other packet\n");
	return (FALSE);
}

void	recv_pong()
{
	t_packet		pong_pkt;

	while (TRUE)
	{
		pong_pkt = ft_pkt_get();
		if (recv_echo_reply(&pong_pkt))
		{
			ft_printf("TIMEOUT\n");
			break ;
		}
		if (check_reply(&pong_pkt))
			break ;
	}
}
