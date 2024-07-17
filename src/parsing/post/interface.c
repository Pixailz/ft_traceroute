/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:49 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 14:45:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_bool pp_interface(void)
{
	t_opt	*opt;
	char	*ptr;

	opt = ft_optget("interface");
	if (!opt || !opt->value)
		ptr = "eth0";
	else
		ptr = opt->value->value;
	ft_pdeb("interface: %s\n", ptr);
	return (FALSE);
}
