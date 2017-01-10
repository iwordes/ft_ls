/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:54:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 12:57:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** List the contents of a directory, and if applicable, all subdirectories.
*/

char		ls_list(const char *path, t_ls *conf)
{
	char		*subpath;
	t_ent		**table;
	unsigned	i;

	(conf->multiple_targets) && ft_printf("%s:\n", path);
	if ((table = ls_listdir(path, conf)) == NULL)
		return (FALSE);
	ls_table_sort(table, sort_name, conf->sort_rev);
	ls_table_fmt(path, table, conf);
	i = ~0;
	if (conf->recurse)
		while (table[i += 1] != NULL)
			if (LS_ISDIR(table[i]) && !ft_strequ(table[i]->name, ".")
			&& !ft_strequ(table[i]->name, ".."))
			{
				write(1, "\n", 1);
				conf->multiple_targets = TRUE;
				LS_MGUARD(subpath = fs_join(path, table[i]->name));
				ls_list(subpath, conf) || err_list(subpath);
				free(subpath);
			}
	ls_destroy_table(table);
	return (TRUE);
}
