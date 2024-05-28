/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/05/28 23:47:11 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_bin	run(int ac, char **av)
{
	int	ret;

	ret = parse_opts(ac, av);
	if (ret == BIT_01)
		return (ft_opt_exec_cmd());
	else if (ret != 0)
		return (WRONG_ARG);
	if (init_signal())
		return (FAILED_INIT_SIGNAL);
	if (init_socket())
		return (FAILED_INIT_SOCKET);
	if (init_probs())
		return (FAILED_INIT_PROBS);
	if (init_table())
		return (FAILED_INIT_TABLE);
	exec();
	return (ret);
}

int	main(int ac, char **av)
{
	char	ret = 0;

	ret = run(ac, av);
	ft_free_opts();
	free_probs();
	return (ret);
}
