/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:15:28 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 15:08:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern int		CURRENT_HOP;
extern int		NB_PROB;
extern t_prob	**PROBS;
char			*COLOR;

static	t_bool	is_same_ip(t_uint32 base_id)
{
	t_uint32	ip;
	int			counter;

	ip = PROBS[base_id]->ip;
	counter = 0;
	while (counter < NB_PROB)
	{
		if (!PROBS[base_id + counter])
		{
			counter++;
			continue ;
		}
		if (PROBS[base_id + counter]->ip != ip)
			return (FALSE);
		ip = PROBS[base_id + counter]->ip;
		counter++;
	}
	return (TRUE);
}

static	void	print_stat_main(t_uint32 base_id)
{
	t_bool	same_ip;

	same_ip = is_same_ip(base_id);
	if (!(CURRENT_HOP == 1))
	{
		ft_printf(CSI "2K" CSI "1A");
		print_stat_separator();
	}
	for (int i = 0; i < NB_PROB; i++)
	{
		print_stat_line(
			i,
			PROBS[base_id + i]->ip,
			PROBS[base_id + i]->ts,
			same_ip
		);
	}
	print_stat_footer();
}

void	print_stat(void)
{
	t_uint32	id;
	t_uint32	base_id;

	id = CURRENT_HOP - 1;
	COLOR = RAINBOW_C(id);
	base_id = id * NB_PROB;
	print_stat_main(base_id);
}
