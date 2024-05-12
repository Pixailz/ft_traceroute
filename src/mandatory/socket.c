/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:47:31 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/12 18:14:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	SOCKET = 0;

int	ft_create_sock_echo(void)
{
	struct timeval	tv;

	if (getuid())
		return (1);
	SOCKET = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (SOCKET == -1)
		return (2);
	tv.tv_usec = 0;
	tv.tv_sec = 2;
	if (setsockopt(SOCKET, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1)
		return (3);
	if (setsockopt(SOCKET, IPPROTO_IP, IP_HDRINCL, (int [1]){1}, \
															sizeof(int)) == -1)
		return (4);
	return (0);
}

int	init_socket(void)
{
	int	retv;

	retv = ft_create_sock_echo();
	if (retv)
	{
		if (retv == 1)
			ft_perr("%s: Lacking privilege for icmp packet\n", PROG_NAME);
		if (retv == 2)
			ft_perr("get_sock_echo: failed to get raw socket\n");
		if (retv == 3)
			ft_perr("get_sock_echo: failed to set timeout on recv\n");
		if (retv == 4)
			ft_perr("get_sock_echo: failed to set IP_HDRINCL\n");
		return (BIT_01);
	}
	return (BIT_00);
}
