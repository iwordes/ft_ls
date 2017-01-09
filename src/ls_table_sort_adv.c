/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_sort_adv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 10:20:41 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 20:08:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define IN_ORDER(N) ((asc) ? ((N) < 0) : ((N) > 0))

/*
** Secondary sort based on two keys: Any sorted chunk of the first will
** be sorted by the second.
*/

void	ls_table_sort_adv(t_ent **table, long (*c1)(t_ent*, t_ent*),
										long (*c2)(t_ent*, t_ent*), char asc)
{
	long	diff;
	t_ent	*tmp;
	size_t	i;

	i = 0;
	while (table[i] != NULL && table[i += 1] != NULL)
	{
		if (c1(table[i - 1], table[i]) == 0)
			if ((diff = c2(table[i - 1], table[i])) != 0 && !IN_ORDER(diff))
			{
				tmp = table[i--];
				table[i + 1] = table[i];
				while (i > 0 && c1(table[i - 1], table[i]) == 0
					&& (diff = c2(table[i], tmp)) && !IN_ORDER(diff))
				{
					table[i] = table[i - 1];
					i -= 1;
				}
				table[i] = tmp;
			}
	}
}
