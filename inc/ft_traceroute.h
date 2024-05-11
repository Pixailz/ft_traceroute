/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 23:02:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "libft.h"

# include <signal.h>
/*
	signal(),
	SIG_IGN,
	SIG_ERR
	SIGALRM
 */

typedef enum e_err_traceoute {
	WRONG_ARG			= 2,
	FAILED_INIT_SIGNAL	= 3,
	FAILED_INIT_SOCKET	= 4,
}	t_err_traceroute;

# define PACK_TOT_LEN_UDP	PACK_LEN_IP + PACK_LEN_UDP + ICMP_HDR_PADDING
# define PACK_TOT_LEN_ICMP	PACK_LEN_IP + PACK_LEN_ICMP_ECHO + ICMP_HDR_PADDING

# define TIMEOUT		1

# define TRACEROUTE_BASE_PORT 33434

/* ########################################################################## */
/* FILES */
/* ##### */

// error.c
void		print_error_parsing(t_bin retv);
t_bin		print_error(t_bin retv);

// execution.c
void		inc_traceroute_lvl(t_packet *pack);
void		exec(void);

// main.c
t_bin		run(int ac, char **av);
int			main(int ac, char **av);

// parsing/cmd/help.c
void		help_header(void);
void		help_part_1(void);
void		help_footer(void);
t_bin		help(void);

// parsing/cmd/usage.c
t_bin		usage(void);

// parsing/parse.c
t_bin		post_parse(void);
t_bin		parse_opts(int ac, char **av);

// print_packet.c
void		packet_print(void *pkt);

// recv_pong.c
void		recv_pong();

// send_ping.c
t_bool		send_ping(t_packet pack);

// signal.c
t_bin		init_signal(void);

// socket.c
int			ft_create_sock_echo(void);
int			init_socket(void);

/* ########################################################################## */

#endif //FT_TRACEROUTE_H
