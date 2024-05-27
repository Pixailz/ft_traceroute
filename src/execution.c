/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/25 13:18:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern char		*TARGET_STR;
extern t_int4	TARGET_IP;
extern t_prob	**PROBS;

t_uint8			CURRENT_TTL = 0;

void	inc_ttl(t_packet *pack)
{
	t_iphdr	*pack_ip;

	pack_ip = ft_pkt_get_ip(pack);
	pack_ip->ttl = ++CURRENT_TTL;
}

void	set_port(t_packet *pack, int index)
{
	t_udphdr	*pack_udp;
	t_uint32	port;

	pack_udp = ft_pkt_get_udp(pack);
	port = ft_htons(TRT_BASE_PORT + index);
	pack_udp->src_port = port;
	pack_udp->dst_port = port;
}

static t_packet	get_udp_packet(void)
{
	t_packet	pack;
	t_iphdr		*pack_ip;
	t_udphdr	*pack_udp;

	pack = ft_pkt_get();
	pack_ip = ft_pkt_get_ip(&pack);
	ft_pkt_fill_ip_default(pack_ip);
	pack_ip->total_len = PACK_TOT_LEN_UDP;
	pack_ip->dst_addr = TARGET_IP;
	pack_ip->ttl = CURRENT_TTL;
	pack_ip->identification = ft_htons(420);
	pack_ip->fragment_off = ft_htons(
		ft_pkt_fragment_offset(IPHDR_F_DONT_FRAG, 0)
	);
	pack_ip->protocol = IPPROTO_UDP;
	pack_ip->dst_addr = ft_htonl(TARGET_IP);

	pack_udp = ft_pkt_get_udp(&pack);
	pack_udp->length = ft_htons(PACK_LEN_UDP);
	return (pack);
}

void	exec(void)
{
	t_packet	pack;
	t_uint32	i;
	t_uint32	retv;

	pack = get_udp_packet();
	i = 0;
	print_stat_header();
	while (i < TRT_MAX_HOP * TRT_NB_PROB)
	{
		set_port(&pack, i);
		if (i % TRT_NB_PROB == 0)
			inc_ttl(&pack);
		send_ping(pack);
		retv = recv_pong(i);
		if (i % TRT_NB_PROB == 2)
		{
			print_stat();
			if (retv == 2)
				break ;
		}
		i++;
	}
	print_stat_footer();
}
