/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:42:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern t_int4	TARGET_IP;
extern t_uint8	CURRENT_TTL;

char			*TARGET_STR = FT_NULL;

t_bin	post_parse(void)
{
	t_opts	*opts;

	opts = ft_get_opts(0);
	if (ft_opts_len(opts) != 1)
	{
		ft_perr("Only one arg is needed\n");
		return (WRONG_ARG);
	}
	TARGET_STR = pp_target(opts);
	if (pp_ip(TARGET_STR))
		return (WRONG_ARG);
	pp_interface();
	pp_max_hop();
	pp_start_hop();
	pp_nb_prob();
	pp_base_port();
	pp_ip_identification();
	CURRENT_TTL--;
	pp_src_ip();
	pp_tos();
	return (BIT_00);
}

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd_cmd("help", '?', help);
	ft_optadd_cmd("usage", 0, usage);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("max-hop", 'm', OPT_SINGLE);
	ft_optadd("nb-prob", 'n', OPT_SINGLE);
	ft_optadd("ip-identification", 'I', OPT_SINGLE);
	ft_optadd("resolve-ip", 'r', OPT_FLAG);
	ft_optadd("start-hop", 'S', OPT_SINGLE);
	ft_optadd("interface", 'i', OPT_SINGLE);
	ft_optadd("source-ip", 's', OPT_SINGLE);
	ft_optadd("tos", 't', OPT_SINGLE);

	ft_optadd("base-port", 'b', OPT_SINGLE);

	ft_optparse(ac, av);
	return (ft_opt_post_parse(post_parse));
}
