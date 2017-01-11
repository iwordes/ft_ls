/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:12:34 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:02:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Sort a NULL-terminated array of t_ent* by the method specified.
** Sorts by ascending order if `asc` is enabled.
*/

#define IN_ORDER(N) ((asc) ? ((N) < 0) : ((N) > 0))

void	ls_table_sort(t_ent **table, long (*cmp)(t_ent*, t_ent*), char asc)
{
	long	diff;
	t_ent	*tmp;
	size_t	i;

	i = 0;
	while (table[i] != NULL && table[i += 1] != NULL)
	{
		if ((diff = cmp(table[i - 1], table[i])) != 0 && !IN_ORDER(diff))
		{
			tmp = table[i--];
			table[i + 1] = table[i];
			while (i > 0 && (diff = cmp(table[i], tmp)) && !IN_ORDER(diff))
			{
				table[i] = table[i - 1];
				i -= 1;
			}
			table[i] = tmp;
		}
	}
}
