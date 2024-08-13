/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:49 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/12 11:59:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

char	*INTERFACE = FT_NULL;

t_bool pp_interface(void)
{
	t_opt	*opt;

	opt = ft_optget("interface");
	if (!opt || !opt->value)
		return (FALSE);
	INTERFACE = opt->value->value;
	return (FALSE);
}
