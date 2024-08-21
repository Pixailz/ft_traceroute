/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:39:45 by brda-sil         ###   ########.fr       */
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
Base options: \n\
\n\
  -?, --help                       Give this help list.\n\
      --usage                      Give a short usage message.\n\
  -V, --version                    Print program version.\n\
  -v, --verbose                    Verbose output.\n\
  -m, --max-hop NUM                Set the max number of hops.\n\
  -n, --nb-prob NUM                Set the number of probes per hop.\n\
                                   Must be between 1-5.\n\
  -r, --resolve-ip                 Try to resolve IP addresses to their domain names.\n\
  -S, --start-hop                  Start from hop NUM (default 1).\n\
  -i, --interface INTERFACE        Bind the interface INTERFACE to the socket\n\
\n\
IP options: \n\
\n\
  -I, --ip-identification NUM      Set the IP identification.\n\
  -s, --source-ip IP               Set the source IP address.\n\
  -t, --tos TOS                    Set the TOS.\n\
\n\
UDP options: \n\
\n\
  -b, --base-port                  Start from port NUM (default 33434).\n\
\n\
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
