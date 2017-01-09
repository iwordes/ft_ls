/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:02:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 20:08:12 by iwordes          ###   ########.fr       */
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
	LS_MGUARD(table_copy = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	i = ~0;
	while ((i += 1) <= l)
		table_copy[i] = table[i];
	ls_table_sort(table_copy, conf->order, conf->sort_rev);
	ls_table_sort_adv(table_copy, conf->order, sort_name, conf->sort_rev);
	ls_table_print(table_copy, conf);
	(void)parent;
}
