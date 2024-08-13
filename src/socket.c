/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:47:31 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/13 21:24:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern	char*	INTERFACE;
int				SOCKET_RECV = 0;
int				SOCKET_SEND = 0;

t_bool	bind_interface_socket(int *sock)
{
	if (!INTERFACE)
		return (FALSE);
	return (ft_setsockopt_bind_interface(*sock, INTERFACE));
}

int	ft_create_sock_echo(int *sock, t_bool bind)
{
	if (getuid())
		return (1);
	*sock = ft_socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (*sock == -1)
		return (2);
	if (ft_setsockopt_timeout(*sock, TRT_TIMEOUT))
		return (3);
	if (ft_setsockopt_ipheader(*sock))
		return (4);
	if (bind)
		if (bind_interface_socket(sock))
			return (5);
	return (0);
}

int	init_socket(int *sock, t_bool bind)
{
	int	retv;

	retv = ft_create_sock_echo(sock, bind);
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
		if (bind && retv == 5)
			ft_perr("get_sock_echo: failed to bind interface\n");
		return (BIT_01);
	}
	return (BIT_00);
}

int	init_sockets(void)
{
	int retv;

	retv = 0;

	if ((retv = init_socket(&SOCKET_RECV, FALSE)))
		return (retv);
	if ((retv = init_socket(&SOCKET_SEND, TRUE)))
		return (retv);
	return (retv);
}
