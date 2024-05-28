/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	help_header(void)
{
	ft_putendl_fd("Usage: " PROG_NAME " [OPTION...] ARG", 1);
}

void	help_part_1(void)
{
	ft_putendl_fd("\n\
  -?, --help                       give this help list.\n\
      --usage                      give a short usage message.\n\
  -m, --max-hop=NUM                set the max number of hops.\n\
  -n, --nb-prob=NUM                set the number of probes per hop.\n\
                                   Must be between 1-5.\n\
  -i, --ip-identification=NUM      Set the IP identification (RFC 791)\n\
  -r, --resolve-ip                 Try to resolve IP addresses to their domain names.\n\
  -S, --start-hop                  start from hop NUM (default 1).\n\
  -V, --version                    print program version.\n\
  -v, --verbose                    verbose output.\n\
", 1);
}

void	help_footer(void)
{
	ft_putendl_fd("Report bugs to <pixailz1@gmail.com>.", 1);
}

t_bin	help(void)
{
	help_header();
	help_part_1();
	help_footer();
	return (0);
}
