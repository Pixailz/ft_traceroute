/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:16:02 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/14 16:28:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

char	TABLE[4][0x200];
t_bool	IS_RESOLVE_IP_PRESENT = FALSE;

# define __FIRST_INDEX			108
# define __SECOND_INDEX			156

void	init_table_header(void)
{
	int	index;

	index = __FIRST_INDEX;
	ft_memcpy(TABLE[HEADER], "╭───┬─────────────────┬─────────────", index);
	if (IS_RESOLVE_IP_PRESENT)
	{
		ft_memcpy(TABLE[HEADER] + index, "┬────────────────────────────────────────────────────", __SECOND_INDEX);
		index += __SECOND_INDEX;
	}
	ft_memcpy(TABLE[HEADER] + index, "╮", 4);
	index += 4;
	TABLE[HEADER][index] = 0;
}

void	init_table_main_separator(void)
{
	int	index;

	index = __FIRST_INDEX;
	ft_memcpy(TABLE[MAIN_SEP], "╞═══╪═════════════════╪═════════════", index);
	if (IS_RESOLVE_IP_PRESENT)
	{
		ft_memcpy(TABLE[MAIN_SEP] + index, "╪════════════════════════════════════════════════════", __SECOND_INDEX);
		index += __SECOND_INDEX;
	}
	ft_memcpy(TABLE[MAIN_SEP] + index, "╡", 4);
	index += 4;
	TABLE[MAIN_SEP][index] = 0;
}

void	init_table_header_separator(void)
{
	int	index;

	index = __FIRST_INDEX;
	ft_memcpy(TABLE[HEADER_SEP], "┝━━━┿━━━━━━━━━━━━━━━━━┿━━━━━━━━━━━━━", index);
	if (IS_RESOLVE_IP_PRESENT)
	{
		ft_memcpy(TABLE[HEADER_SEP] + index, "┿━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", __SECOND_INDEX);
		index += __SECOND_INDEX;
	}
	ft_memcpy(TABLE[HEADER_SEP] + index, "┥", 4);
	index += 4;
	TABLE[HEADER_SEP][index] = 0;
}

void	init_table_footer(void)
{
	int	index;

	index = __FIRST_INDEX;
	ft_memcpy(TABLE[FOOTER], "╰───┴─────────────────┴─────────────", index);
	if (IS_RESOLVE_IP_PRESENT)
	{
		ft_memcpy(TABLE[FOOTER] + index, "┴────────────────────────────────────────────────────", __SECOND_INDEX);
		index += __SECOND_INDEX;
	}

	ft_memcpy(TABLE[FOOTER] + index, "╯", 4);
	index += 4;
	TABLE[FOOTER][index] = 0;
}

int	init_table(void)
{
	t_opt	*opt;

	opt = ft_optget("resolve-ip");
	if (opt && opt->is_present)
		IS_RESOLVE_IP_PRESENT = TRUE;
	init_table_header();
	init_table_header_separator();
	init_table_main_separator();
	init_table_footer();
	return (0);
}
