/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:50:01 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/27 10:16:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern char	*COLOR;
extern int	CURRENT_TTL;

void	print_padded_ip(t_int4 ip, char *COLOR)
{
	char *ip_str;

	ip_str = ft_getip_str(ft_htonl(ip));
	ft_printf(" %s%15s%s ", COLOR, ip_str, RST);
	free(ip_str);
}

void	print_stat_header(void)
{
	ft_printf(
		TRT_TABLE_COLOR
		"╭───┬─────────────────┬─────────────╮\n"
		"│" RST UND "HOP" RUND TRT_TABLE_COLOR
		"│" RST "       " UND "IP" RUND "        " TRT_TABLE_COLOR
		"│" RST "    " UND "PROBS" RUND "    " TRT_TABLE_COLOR "│\n"
		"╞═══╪═════════════════╪═════════════╡\n" RST
	);
}

void	print_stat_footer(void)
{
	ft_printf(
		TRT_TABLE_COLOR
		"╰───┴─────────────────┴─────────────╯\n"
		RST
	);
}

void	print_stat_separator(void)
{
	ft_printf(
		TRT_TABLE_COLOR
		"┝━━━┿━━━━━━━━━━━━━━━━━┿━━━━━━━━━━━━━┥\n"
		RST
	);
}

void	print_stat_line(int	i, t_int4 ip, t_ts ts, t_bool same_ip)
{
	if (i)
		ft_printf(TRT_TABLE_COLOR "│" RST "   " TRT_TABLE_COLOR "│" RST);
	else
		ft_printf(TRT_TABLE_COLOR "│" RST "%s%3d" RST TRT_TABLE_COLOR "│" RST, COLOR, CURRENT_TTL);
	if (ip)
	{
		if (i && same_ip)
			ft_printf("%17s", "");
		else
			print_padded_ip(ip, COLOR);
	}
	else
		ft_printf(" %s───────────────%s ", COLOR, RST);
	ft_printf(TRT_TABLE_COLOR "│" RST);
	if (!ts)
		ft_printf("      %s*" RST "      ", COLOR);
	else
		ft_printf("%s%5d.%03d ms" RST " ", COLOR, ts / 1000, ts % 1000);
	ft_printf(TRT_TABLE_COLOR "│" RST "\n");
}
