/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 21:34:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int	CURRENT_TTL;

char		*TARGET_STR = FT_NULL;
t_int4		TARGET_IP = 0;
int			MAX_HOP = 0;
int			NB_PROB = 0;
t_uint16	IP_IDENT = 0;

static t_size get_opt_len(t_opts *opts)
{
	t_opt_value	*ptr;
	int			nb_opts;

	ptr = opts->value;
	nb_opts = 0;
	while (ptr)
	{
		if (ptr->value)
			nb_opts++;
		ptr = ptr->next;
	}
	return (nb_opts);
}

static char *get_target(t_opts *opts)
{
	t_opt_value	*ptr;

	ptr = opts->value;
	if (!ptr || !ptr->value || (ptr->next && ptr->next->value))
		return (FT_NULL);
	return (ptr->value);
}

static t_bool	get_ip(char *target)
{
	t_int4	ip_tmp;

	if (!ft_strncmp(target, "0.0.0.0", 7))
		return (0);
	ip_tmp = ft_ipstr(target);
	if (ip_tmp)
		return (ip_tmp);
	ip_tmp = ft_htoi4(target, FT_NULL);
	if (ip_tmp)
		return (ip_tmp);
	ft_perr("%s: unknown host\n", PROG_NAME);
	return (TRUE);
}

static	int	get_max_hop(void)
{
	t_opt	*max_hop;
	int		value;

	max_hop = ft_optget("max-hop");
	if (!max_hop || !max_hop->value)
		return (TRT_MAX_HOP);
	value = ft_atoi(max_hop->value->value);
	if (value <= 0)
	{
		ft_perr("Invalid max-hop value. Defaulting to %d\n", TRT_MAX_HOP);
		value = TRT_MAX_HOP;
	}
	return (value);
}

static	int get_nb_prob(void)
{
	t_opt	*nb_prob;
	int		value;

	nb_prob = ft_optget("nb-prob");
	if (!nb_prob || !nb_prob->value)
		return (TRT_NB_PROB);
	value = ft_atoi(nb_prob->value->value);
	if (value <= 0)
	{
		ft_perr("nb-prob value too low. Defaulting to %d\n", 1);
		value = 1;
	}
	else if (value > 5)
	{
		ft_perr("nb-prob value too high. Defaulting to %d\n", 5);
		value = 5;
	}
	return (value);
}

static	int get_ip_identification(void)
{
	t_opt	*ip_ident;
	int		value;

	ip_ident = ft_optget("ip-identification");
	if (!ip_ident || !ip_ident->value)
		return (TRT_IP_IDENT);
	value = ft_atoi(ip_ident->value->value);
	if (value <= 0)
	{
		ft_perr("ip_ident value too low. Defaulting to %d\n", TRT_IP_IDENT);
		value = TRT_IP_IDENT;
	}
	else if (value > 0xffff)
	{
		ft_perr("nb-prob value too high. Defaulting to %d\n", TRT_IP_IDENT);
		value = TRT_IP_IDENT;
	}
	return (value);
}

static	int	get_start_hop(void)
{
	t_opt	*start_hop;
	int		value;

	start_hop = ft_optget("start-hop");
	if (!start_hop || !start_hop->value)
		return (1);
	value = ft_atoi(start_hop->value->value);
	if (value <= 0)
	{
		ft_perr("start-hop value too low. Defaulting to 1\n");
		value = 1;
	}
	if (value > MAX_HOP)
	{
		ft_perr("start-hop value too high. Defaulting to %d\n", MAX_HOP);
		value = MAX_HOP;
	}
	return (value);
}

t_bin	post_parse(void)
{
	t_opts	*opts;

	opts = ft_get_opts(0);
	if (get_opt_len(opts) != 1)
	{
		ft_perr("Only one arg is needed\n");
		return (WRONG_ARG);
	}
	TARGET_STR = get_target(opts);
	TARGET_IP = get_ip(TARGET_STR);
	MAX_HOP = get_max_hop();
	NB_PROB = get_nb_prob();
	IP_IDENT = get_ip_identification();
	CURRENT_TTL = get_start_hop();
	CURRENT_TTL--;
	return (BIT_00);
}

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd_cmd("help", '?', help);
	ft_optadd_cmd("usage", 0, usage);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optadd("max-hop", 'm', OPT_SINGLE);
	ft_optadd("nb-prob", 'n', OPT_SINGLE);
	ft_optadd("ip-identification", 'i', OPT_SINGLE);
	ft_optadd("resolve-ip", 'r', OPT_FLAG);
	ft_optadd("start-hop", 'S', OPT_SINGLE);
	ft_optparse(ac, av);
	return (ft_opt_post_parse(post_parse));
}
