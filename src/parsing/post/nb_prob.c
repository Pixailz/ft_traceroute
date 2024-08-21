/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_prob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:55:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 10:31:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	NB_PROB = TRT_NB_PROB;

void pp_nb_prob(void)
{
	t_opt	*nb_prob;
	int		value;
	int		retv;

	nb_prob = ft_optget("nb-prob");
	if (!nb_prob || !nb_prob->value)
		return ;
	value = ft_patoi(nb_prob->value->value, &retv);
	if (retv)
	{
		ft_perr("nb-prob wrong value. Defaulting to %d\n", 1);
		NB_PROB = 1;
	}
	else if (value <= 0)
	{
		ft_perr("nb-prob value too low. Defaulting to %d\n", 1);
		NB_PROB = 1;
	}
	else if (value > 5)
	{
		ft_perr("nb-prob value too high. Defaulting to %d\n", 5);
		NB_PROB = 5;
	}
	NB_PROB = value;
}
