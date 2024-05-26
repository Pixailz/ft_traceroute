/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:15:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/27 00:59:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int		CURRENT_TTL;
extern t_prob	**PROBS;

void	print_padded_ip(t_int4 ip, char *COLOR)
{
	char *ip_str;

	ip_str = ft_getip_str(ft_htonl(ip));
	ft_printf("%s%15s", COLOR, ip_str);
	free(ip_str);
}

void	print_stat_header(void)
{
	ft_printf(
		GRE
		"╭───┬───────────────┬───────────────────────────────────────╮\n"
		"│" RST UND "HOP" RUND GRE
		"│" RST "      " UND "IP" RUND "       " GRE
		"│" RST "                 " UND "PROBS" RUND
		"                 " GRE "│\n"
		"╞═══╪═══════════════╪═══════════════════════════════════════╡\n" RST
	);
}

void	print_stat_footer(void)
{
	ft_printf(
		GRE
		"╰───┴───────────────┴───────────────────────────────────────╯\n"
		RST
	);
}

t_bool	is_same_ip(t_uint32 base_id)
{
	int		counter;
	t_int4	ip;

	counter = 1;
	ip = PROBS[base_id]->ip;
	while (counter < TRT_NB_PROB)
	{
		if (!PROBS[base_id + counter]->ip)
		{
			counter++;
			continue;
		}
		if (PROBS[base_id + counter]->ip != ip)
			return (FALSE);
		ip = PROBS[base_id]->ip;
		counter++;
	}
	return (TRUE);
}

void	print_stat_ip_same(t_uint32 base_id, char *COLOR)
{
	t_int4	ip;

	ip = PROBS[base_id]->ip;
	ft_printf(GRE "│" RST "%s%3d" GRE "│" RST, COLOR, CURRENT_TTL);
	if (ip)
		print_padded_ip(ip, COLOR);
	else
		ft_printf("%15s");
	ft_printf(GRE "│" RST);
	for (int i = 0; i < TRT_NB_PROB; i++)
	{
		if (!PROBS[base_id + i]->ts)
			ft_printf("      %s*" RST "      ", COLOR);
		else
			ft_printf("%s%5d.%03d ms" RST " ", COLOR,
				PROBS[base_id + i]->ts / 1000,
				PROBS[base_id + i]->ts % 1000
			);
	}

	ft_printf(GRE "│" RST "\n");
}

void	print_stat_ip_differ(t_uint32 base_id, char *COLOR)
{
	t_int4	ip;

	for (int i = 0; i < TRT_NB_PROB; i++)
	{
		ip = PROBS[base_id + i]->ip;
		ft_printf(GRE "│" RST "%s%3d" GRE "│" RST, COLOR, CURRENT_TTL);
		if (ip)
			print_padded_ip(ip, COLOR);
		else
			ft_printf("%15s");
		ft_printf(GRE "│" RST);
		if (!PROBS[base_id + i]->ts)
			ft_printf("      %s*" RST "      ", COLOR);
		else
			ft_printf("%s%5d.%03d ms" RST " ", COLOR,
				PROBS[base_id + i]->ts / 1000,
				PROBS[base_id + i]->ts % 1000
			);
		ft_printf(GRE "│" RST "\n");
	}

}

void	print_stat(void)
{
	t_int4		ip;
	t_uint32	id;
	t_uint32	base_id;
	char		*COLOR;

	id = CURRENT_TTL - 1;
	COLOR = RAINBOW_C(id);
	base_id = id * TRT_NB_PROB;
	if (is_same_ip(base_id))
		print_stat_ip_same(base_id, COLOR);
	else
		print_stat_ip_differ(base_id, COLOR);
}
