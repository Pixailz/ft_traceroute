/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:06:56 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/23 15:21:54 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_prob	**PROBS;

int	init_probs(void)
{
	int	counter;
	int	max_prob;

	max_prob = TRT_MAX_HOP * TRT_NB_PROB;
	PROBS = (t_prob **)ft_calloc(max_prob, sizeof(t_prob *));
	ft_pdeb("MAX EXPECTED PACKET: %d\n", max_prob);
	if (!PROBS)
	{
		ft_perr("%s: Failed to init probs struct\n", PROG_NAME);
		return (BIT_01);
	}
	counter = 0;
	while (counter < max_prob)
	{
		PROBS[counter] = (t_prob *)ft_calloc(1, sizeof(t_prob));
		if (!PROBS[counter])
		{
			ft_perr("%s: Failed to init probs struct\n", PROG_NAME);
			return (BIT_02);
		}
		counter++;
	}
	return (BIT_00);
}

void	free_probs(void)
{
	int	counter;
	int	max_prob;

	max_prob = TRT_MAX_HOP * TRT_NB_PROB;
	counter = 0;
	while(counter < max_prob)
		free(PROBS[counter++]);
	free(PROBS);
}
