/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:02:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 14:09:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
**
*/

void			ls_table_fmt(const char *parent, t_ent **table, t_ls *conf)
{
	t_ent		**table_copy;
	unsigned	i;
	unsigned	l;

	ls_table_align(table);
	l = 0;
	while (table[l] != NULL)
		l += 1;
	if ((table_copy = (t_ent**)malloc(sizeof(void*) * (l + 1))) == NULL)
		// TODO: Handle errors
		return ;
	i = 0;
	while (i <= l)
	{
		table_copy[i] = table[i];
		i += 1;
	}
	ls_table_sort(table_copy, conf->order, conf->sort_rev);
	ls_table_sort_adv(table_copy, conf->order, sort_name, conf->sort_rev);
	ls_table_print(table_copy, conf);
	(void)parent;
}
