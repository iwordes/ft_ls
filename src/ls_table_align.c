/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_align.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:04:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 11:19:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Move the "." and ".." entries in an entry table to the top.
** Should not be called on a table without "." or ".." entries.
*/

static void	ls_table_align_1(t_ent **table)
{
	t_ent	*tmp;
	size_t	i;

	i = 0;
	while (table[(i += 1)] != NULL)
	{
		if (ft_strequ(table[i], "."))
		{
			tmp = table[i];
			while (i-- > 0)
				table[i] = table[i + 1];
			table[i] = tmp;
			break ;
		}
	}
}

static void	ls_table_align_2(t_ent **table)
{
	t_ent	*tmp;
	size_t	i;

	i = 1;
	while (table[(i += 1)] != NULL)
	{
		if (ft_strequ(table[i], ".."))
		{
			tmp = table[i];
			while (i-- > 1)
				table[i] = table[i + 1];
			table[i] = tmp;
			break ;
		}
	}
}

void	ls_table_align(t_ent **table)
{
	ls_table_align_1(table);
	ls_table_align_2(table);
}
