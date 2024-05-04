/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/04/27 01:22:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "libft.h"

/* ########################################################################## */
/* FILES */
/* ##### */

// data/error.c
void		print_error_parsing(t_bin retv);
t_bin		print_error(t_bin retv);

// data/parsing/cmd/help.c
void		help_header(void);
void		help_part_1(void);
void		help_footer(void);
t_bin		help(void);

// data/parsing/cmd/usage.c
t_bin		usage(void);

// data/parsing/parse.c
t_bin		post_parse(void);
t_bin		parse_opts(int ac, char **av);

// main.c
t_bin		run(int ac, char **av);
int			main(int ac, char **av);

/* ########################################################################## */

#endif //FT_TRACEROUTE_H
