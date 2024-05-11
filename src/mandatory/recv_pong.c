/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_pong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:53:19 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 21:13:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int SOCKET;

static t_bool	recv_echo_reply(t_packet *pong_pkt)
{
	struct iovec	io;
	struct msghdr	msg;
	long			ret;

	ft_memset(&io, 0, sizeof(io));
	ft_memset(&msg, 0, sizeof(msg));
	io.iov_base = pong_pkt->data;
	io.iov_len = sizeof(t_icmphdr_time_exceed);
	msg.msg_iov = &io;
	msg.msg_iovlen = 1;
	ret = recvmsg(SOCKET, &msg, 0);
	return (ret == -1);
}

static t_bool	check_reply(t_packet *pkt)
{
	// t_icmphdr_echo	*icmphdr_echo;

	// icmphdr_echo = ft_pkt_get_icmp_echo(pkt);
	// if (icmphdr_echo->type != ICMP_ECHOREPLY)
	// {
	// 	if ((int)icmphdr_echo->type == ICMP_ECHO)
	// 		return (FALSE);
	// 	print_icmp_error(pkt->data);
	// 	conf->stats.nb_err++;
	// }
	// else
	// {
	// 	conf->stats.nb_recv++;
	// 	print_pong_stats(pkt->data, icmphdr_echo);
	// }
	return (TRUE);
}

void	recv_pong()
{
	t_packet		pong_pkt;

	pong_pkt = ft_pkt_get();
	while (TRUE)
	{
		ft_bzero(pong_pkt.data, sizeof(pong_pkt.data));
		if (recv_echo_reply(&pong_pkt))
		{
			ft_printf("TIMEOUT\n");
			break ;
		}
		if (check_reply(&pong_pkt))
			break ;
	}
}
