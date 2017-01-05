/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:02:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:07:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
**
*/

void			ls_table_fmt(const char *parent, t_ent **o_ent, t_ls *conf)
{
	t_ent		**ent;
	unsigned	i;
	unsigned	l;

	l = 0;
	while (o_ent[l] != NULL)
		l += 1;
	if ((ent = (t_ent**)malloc(sizeof(void*) * (l + 1))) == NULL)
		// TODO: Handle errors
		return ;
	i = 0;
	while (i <= l)
	{
		ent[i] = o_ent[i];
		i += 1;
	}
	ls_table_sort(ent, conf->order, conf->sort_rev);
	ls_table_print(ent, conf);
	(void)parent;
}
