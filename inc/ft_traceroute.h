/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/12 13:43:59 by brda-sil         ###   ########.fr       */
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
	FAILED_INIT_TABLE	= 6,
}	t_err_traceroute;

typedef enum e_table_type {
	HEADER,
	HEADER_SEP,
	MAIN_SEP,
	FOOTER
}	t_table_type;

# define PACK_TOT_LEN_UDP		PACK_LEN_IP + PACK_LEN_UDP + ICMP_HDR_PADDING
# define PACK_TOT_LEN_ICMP		PACK_LEN_IP + PACK_LEN_ICMP_ECHO + ICMP_HDR_PADDING
# define PACK_TOT_LEN_ICMP_TIME	PACK_TOT_LEN_ICMP + PACK_TOT_LEN_ICMP

// Some default value

// Traceroute default ip IDENTIFICATION
# define TRT_IP_IDENT		420

// Color for the traceroute table
# define TRT_TABLE_COLOR	DIM GRE

// Traceroute base port for dummy udp packet
# define TRT_BASE_PORT		33434

// Number to packet to send at the same host
# define TRT_NB_PROB		3

// Max hop (TTL)
# define TRT_MAX_HOP		30

// Set timemout for a request, in µs
# define TRT_TIMEOUT		500000
// # define TRT_TIMEOUT		30000

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

// parsing/post/interface.c
t_bool		pp_interface(void);

// parsing/post/ip.c
t_bool		pp_ip(char *target);

// parsing/post/ip_identification.c
int			pp_ip_identification(void);

// parsing/post/max_hop.c
int			pp_max_hop(void);

// parsing/post/nb_prob.c
int			pp_nb_prob(void);

// parsing/post/start_hop.c
int			pp_start_hop(void);

// parsing/post/target.c
char		*pp_target(t_opts *opts);

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
void		ft_traceroute_interrupt(int sig);
t_bin		init_signal(void);

// socket.c
t_bool		bind_interface_socket(int *sock);
int			ft_create_sock_echo(int *sock, t_bool bind);
int			init_socket(int *sock, t_bool bind);
int			init_sockets(void);

// stat/init.c
void		init_table_header(void);
void		init_table_main_separator(void);
void		init_table_header_separator(void);
void		init_table_footer(void);
int			init_table(void);

// stat/main.c
void		print_stat(void);

// stat/utils.c
void		print_padded_ip(t_int4 ip, char *COLOR);
void		print_stat_header(void);
void		print_stat_footer(void);
void		print_stat_separator(void);
void		print_stat_line(int	i, t_int4 ip, t_ts ts, t_bool same_ip);

/* ########################################################################## */

#endif //FT_TRACEROUTE_H
