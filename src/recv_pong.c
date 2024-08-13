/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_pong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:53:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 22:11:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int		SOCKET_RECV;
extern t_prob	**PROBS;
extern t_ts		LAST_SENDED;
extern t_bool	IS_INTERRUPTED;

t_ts			LAST_RECV;

static t_bool	recv_echo_reply(t_packet *pong_pkt)
{
	long			ret;

	ret = recvfrom(
		SOCKET_RECV,			// SOCKET
		pong_pkt->data,			// BUFFER
		PACK_TOT_LEN_ICMP_TIME,	// LEN
		0,						// FLAG
		FT_NULL,				// SOCK ADDR FROM
		FT_NULL					// SOCK ADDR FROM LEN
	);
	return (ret == -1);
}

t_uint16	get_ori_port(t_icmphdr_time_exceed pkt)
{
	return ((pkt.ori_data[0] << 8) | pkt.ori_data[1]);
}

t_int32		get_index(t_icmphdr_time_exceed pkt)
{
	return (get_ori_port(pkt) - TRT_BASE_PORT);
}


static	void	set_stat(int index, t_int4 ip)
{
	PROBS[index]->ip = ip;
	PROBS[index]->ts = LAST_RECV - LAST_SENDED;
}

static t_uint32	check_reply(t_packet *pkt, t_uint32 exp_port)
{
	t_iphdr					*pack_ip;
	t_icmphdr_time_exceed	*pack_icmp;
	t_uint32				ori_port;

	pack_ip = ft_pkt_get_ip(pkt);
	pack_icmp = ft_pkt_get_icmp_time_exceed(pkt);
	ori_port = get_ori_port(*pack_icmp);
	if (pack_icmp->type == ICMP_TIME_EXCEEDED && ori_port == exp_port)
	{
		ft_pdeb("Time Exceeded\n");
		set_stat(get_index(*pack_icmp), pack_ip->src_addr);
		return (1);
	}
	else if (	pack_icmp->type == ICMP_DEST_UNREACH &&
				pack_icmp->code == ICMP_PORT_UNREACH)
	{
		ft_pdeb("Dest Reached\n");
		set_stat(get_index(*pack_icmp), pack_ip->src_addr);
		return (2);
	}
	return (0);
}

t_uint32	recv_pong(int index)
{
	t_packet	pong_pkt;
	t_uint32	retv;

	while (!IS_INTERRUPTED)
	{
		pong_pkt = ft_pkt_get();
		if (recv_echo_reply(&pong_pkt))
		{
			ft_pdeb("TIMEOUT\n");
			return 0;
		}
		LAST_RECV = ft_get_ts();
		retv = check_reply(&pong_pkt, TRT_BASE_PORT + index);
		if (retv)
			return retv;
	}
	return (0);
}
