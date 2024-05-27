/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:17:44 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/11 21:19:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_bin	init_signal(void)
{
	if (signal(SIGALRM, SIG_IGN) == SIG_ERR)
	{
		ft_perr("signal: failed to ingore SIGALRM\n");
		return (BIT_01);
	}
	return (BIT_00);
}
