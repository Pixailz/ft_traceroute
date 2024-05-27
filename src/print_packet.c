/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_packet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:02:48 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/12 17:28:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	packet_print(void *pkt)
{
	ft_dprintf(1, "%s", FMT_BIN_BAR);
	ft_pkt_print_ip(1, pkt);
	ft_pkt_print_udp(1, pkt + PACK_LEN_IP);
}
