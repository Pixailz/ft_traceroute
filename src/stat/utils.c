/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:50:01 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 16:30:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern char		*COLOR;
extern int		CURRENT_TTL;
extern char		TABLE[4][0x200];
extern t_bool	IS_RESOLVE_IP_PRESENT;

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
		TRT_TABLE_COLOR "%s\n"
		"│" RST UND "HOP" RUND TRT_TABLE_COLOR
		"│" RST "       " UND "IP" RUND "        " TRT_TABLE_COLOR
		"│" RST "    " UND "PROBS" RUND "    " TRT_TABLE_COLOR
		"│" RST
		, TABLE[HEADER]
	);
	if (IS_RESOLVE_IP_PRESENT)
		ft_printf(
			"                    " UND "RESOLVED IP" RUND
			"                    " TRT_TABLE_COLOR "│" RST
		);
	ft_printf(TRT_TABLE_COLOR "\n%s\n" RST, TABLE[HEADER_SEP]);
}

void	print_stat_footer(void)
{
	ft_printf(TRT_TABLE_COLOR "%s\n" RST, TABLE[FOOTER]);
}

void	print_stat_separator(void)
{
	ft_printf(TRT_TABLE_COLOR "%s\n" RST, TABLE[MAIN_SEP]);
}

void	print_stat_line(int	i, t_int4 ip, t_ts ts, t_bool same_ip)
{
	char	*resolved;

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
	if (IS_RESOLVE_IP_PRESENT)
	{
		ft_printf(TRT_TABLE_COLOR "│" RST);
		if (i && same_ip)
			ft_printf("%51s", "");
		else
		{
			resolved = ft_i4toh(ip);
			if (resolved)
			{
				ft_printf(" %s", COLOR);
				ft_printf("%49s", resolved);
				ft_printf("%s ", RST);
			}
			else if (ip)
			{
				char * ip_str;
				ft_printf(" %s", COLOR);
				ip_str = ft_getip_str(ft_htonl(ip));
				ft_printf("%49s", ip_str);
				free(ip_str);
				ft_printf("%s ", RST);
			}
			else
				ft_printf("     %s─────────────────────────────────────────%s     ", COLOR, RST);
			free(resolved);
		}
	}
	ft_printf(TRT_TABLE_COLOR "│" RST "\n");
}
