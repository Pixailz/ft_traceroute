/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_prob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:55:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 13:56:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int pp_nb_prob(void)
{
	t_opt	*nb_prob;
	int		value;

	nb_prob = ft_optget("nb-prob");
	if (!nb_prob || !nb_prob->value)
		return (TRT_NB_PROB);
	value = ft_atoi(nb_prob->value->value);
	if (value <= 0)
	{
		ft_perr("nb-prob value too low. Defaulting to %d\n", 1);
		value = 1;
	}
	else if (value > 5)
	{
		ft_perr("nb-prob value too high. Defaulting to %d\n", 5);
		value = 5;
	}
	return (value);
}
