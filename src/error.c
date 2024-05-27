/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:04:54 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 19:51:53 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	print_error_parsing(t_bin retv)
{
	if (retv == 2)
	{
		ft_perr("%s: Only one argument needed\n", PROG_NAME);
	}
}

t_bin	print_error(t_bin retv)
{
	if (!retv)
		return retv;
	if (retv <= 2)
		print_error_parsing(retv);
	ft_try_help_usage();
	return retv;
}
