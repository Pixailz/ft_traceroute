/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:26:32 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/27 01:39:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

extern char		*TARGET_STR;
extern t_int4	 TARGET_IP;

t_bin	run(int ac, char **av)
{
	int	ret;

	ret = parse_opts(ac, av);
	if (ret == BIT_01)
		return (ft_opt_exec_cmd());
	else if (ret != 0)
		return (ret);
	return (ret);
}

int	main(int ac, char **av)
{
	char	ret = 0;

	ret = run(ac, av);
	ft_printf("TARGET_STR > %s\n", TARGET_STR);
	ft_printf("TARGET_IP  > ");
	ft_putip_fd(TARGET_IP, 1);
	ft_putchar_fd('\n', 1);
	ft_free_opts();
	return (ret);
}
