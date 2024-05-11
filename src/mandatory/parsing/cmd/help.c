/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:38:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 19:46:42 by brda-sil         ###   ########.fr       */
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
  -?, --help                 give this help list\n\
      --usage                give a short usage message\n\
  -V, --version              print program version\n\
  -v, --verbose              verbose output\n\
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
