/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:01:15 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/05 00:18:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

char	*TARGET_STR = FT_NULL;
t_int4	 TARGET_IP = 0;

static t_size get_opt_len(t_opts *opts)
{
	t_opt_order	*ptr;
	int			nb_opts;

	ptr = opts->opt_order;
	nb_opts = 0;
	while (ptr)
	{
		if (ptr->type == OPT_ORD_VAL)
			nb_opts++;
		ptr = ptr->next;
	}
	return (nb_opts);
}

static char *get_target(t_opts *opts)
{
	t_opt_order	*ptr;

	ptr = opts->opt_order;
	while (ptr)
	{
		if (ptr->type != OPT_ORD_VAL)
			continue ;
		else
			return (ptr->value);
		ptr = ptr->next;
	}
	return (FT_NULL);
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

t_bin	post_parse(void)
{
	t_opts	*opts;
	t_size	 opt_len;

	opts = ft_get_opts(0);
	opt_len = get_opt_len(opts);
	if (opt_len != 1)
		return (2);
	TARGET_STR = get_target(opts);
	TARGET_IP = get_ip(TARGET_STR);
	return (BIT_00);
}

t_bin	parse_opts(int ac, char **av)
{
	ft_optadd_cmd("help", '?', help);
	ft_optadd_cmd("usage", 0, usage);
	ft_optadd("verbose", 'v', OPT_FLAG);
	ft_optparse(ac, av);
	return (ft_opt_post_parse(post_parse));
}
