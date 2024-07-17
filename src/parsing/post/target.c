/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:52:37 by brda-sil          #+#    #+#             */
/*   Updated: 2024/07/17 14:00:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

char *pp_target(t_opts *opts)
{
	t_opt_value	*ptr;

	ptr = opts->value;
	if (!ptr || !ptr->value || (ptr->next && ptr->next->value))
		return (FT_NULL);
	return (ptr->value);
}
