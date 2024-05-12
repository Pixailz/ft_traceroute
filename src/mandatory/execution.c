/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern char		*TARGET_STR;
extern t_int4	TARGET_IP;
int				TRACEROUTE_LVL = 0;

void	inc_traceroute_lvl(t_packet *pack)
{
	t_iphdr		*pack_ip;
	t_udphdr	*pack_udp;
	t_uint16	port;

	pack_ip = ft_pkt_get_ip(pack);
	port = ft_htons(TRACEROUTE_BASE_PORT + TRACEROUTE_LVL);
	TRACEROUTE_LVL++;
	pack_ip->ttl = TRACEROUTE_LVL;
	pack_udp = ft_pkt_get_udp(pack);
	pack_udp->dst_port = port;
	pack_udp->src_port = port;
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
	pack_ip->ttl = TRACEROUTE_LVL;
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
	int			i;

	pack = get_udp_packet();
	i = 0;
	while (i < 20)
	{
		inc_traceroute_lvl(&pack);
		send_ping(pack);
		recv_pong();
		i++;
	}
}
