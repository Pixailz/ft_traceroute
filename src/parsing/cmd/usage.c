/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:02:30 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 19:46:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_bin	usage(void)
{
	ft_dprintf(1, "\
Usage: %s [--verbose] [--help] [--usage] [--version] ARG\n", PROG_NAME);
	return (0);
}
