/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:17:44 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/27 15:15:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_bool	IS_INTERRUPTED = FALSE;

void	ft_traceroute_interrupt(int sig)
{
	if (sig != SIGINT)
		return ;
	ft_pdeb("SIGINT received\n");
	IS_INTERRUPTED = TRUE;
}

t_bin	init_signal(void)
{
	if (signal(SIGALRM, SIG_IGN) == SIG_ERR)
	{
		ft_perr("signal: failed to ingore SIGALRM\n");
		return (BIT_01);
	}
	if (signal(SIGINT, &ft_traceroute_interrupt) == SIG_ERR)
	{
		ft_perr("signal: failed to set SIGINT\n");
		return (BIT_02);
	}
	return (BIT_00);
}
