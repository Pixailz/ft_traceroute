/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:52:37 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/21 09:49:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_uint8	TOS = 0;

void	pp_tos(void)
{
	t_opt	*opt;
	int		retv;

	opt = ft_optget("tos");
	if (!opt || !opt->value)
		return ;
	TOS = ft_patoi(opt->value->value, &retv);
	if (retv)
		ft_perr("tos wrong value\n");
}
