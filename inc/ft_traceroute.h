/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/24 00:50:02 by brda-sil         ###   ########.fr       */
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
# include <sys/time.h>
/*
 gettimeofday()
 */

typedef enum e_err_traceoute {
	WRONG_ARG			= 2,
	FAILED_INIT_SIGNAL	= 3,
	FAILED_INIT_SOCKET	= 4,
	FAILED_INIT_PROBS	= 5,
}	t_err_traceroute;

# define PACK_TOT_LEN_UDP		PACK_LEN_IP + PACK_LEN_UDP + ICMP_HDR_PADDING
# define PACK_TOT_LEN_ICMP		PACK_LEN_IP + PACK_LEN_ICMP_ECHO + ICMP_HDR_PADDING
# define PACK_TOT_LEN_ICMP_TIME	PACK_TOT_LEN_ICMP + PACK_TOT_LEN_ICMP

# define A_SEC			1000000

// Traceroute base port for dummy udp packet
# define TRT_BASE_PORT	33434

// Number to packet to send at the same host
# define TRT_NB_PROB	3

// Max hop (TTL)
# define TRT_MAX_HOP	30

// Set timemout for a request, in µs
# define TRT_TIMEOUT	500000

typedef long	t_ts;

typedef struct	s_prob {
	t_uint32	ip;
	t_ts		ts;
}	t_prob;

/* ########################################################################## */
/* FILES */
/* ##### */

// error.c
void		print_error_parsing(t_bin retv);
t_bin		print_error(t_bin retv);

// execution.c
void		inc_ttl(t_packet *pack);
void		set_port(t_packet *pack, int index);
void		exec(void);

// ft_get_ts.c
t_ts		ft_get_ts(void);

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

// probs.c
int			init_probs(void);
void		free_probs(void);

// recv_pong.c
t_uint16	get_ori_port(t_icmphdr_time_exceed pkt);
t_int32		get_index(t_icmphdr_time_exceed pkt);
t_uint32	recv_pong(int index);

// send_ping.c
t_bool		send_ping(t_packet pack);

// signal.c
t_bin		init_signal(void);

// socket.c
int			ft_create_sock_echo(void);
int			init_socket(void);

// stat.c
void		print_padded_ip(t_int4 ip, char *COLOR);
void		print_stat_header(void);
void		print_stat_footer(void);
t_bool		is_same_ip(t_uint32 base_id);
void		print_stat_ip_same(t_uint32 base_id, char *COLOR);
void		print_stat_ip_differ(t_uint32 base_id, char *COLOR);
void		print_stat(void);

/* ########################################################################## */

#endif //FT_TRACEROUTE_H
