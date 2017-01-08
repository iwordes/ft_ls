/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:54:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 13:29:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	recurse_(const char *path, t_ent *ent, t_ls *conf);

/*
** List the contents of a directory, and if applicable, all subdirectories.
*/
/*
** Potential optimizations:
** - Reduce the number of malloc/free calls by using a list(-like) struct OR
**   by using a dirent**.
*/
/*
** If recurse_ ever runs, there is at least one entry already printed to screen.
*/

void	ls_list(const char *path, t_ls *conf)
{
	t_ent			**table;
	unsigned		i;

	if ((table = ls_listdir(path, conf)) == NULL)
		exit(-1);
	ls_table_sort(table, sort_name, conf->sort_rev);
	ls_table_fmt(path, table, conf);
	i = ~0;
	if (conf->recurse)
		while (table[i += 1] != NULL)
			recurse_(path, table[i], conf);
	i = ~0;
	while (table[i += 1] != NULL)
		free(table[i]);
	free(table);
}

static void	recurse_(const char *path, t_ent *ent, t_ls *conf)
{
	char	*subpath;

	if (S_ISDIR(ent->info.st_mode))
		if (!(ft_strequ(ent->name, ".") || ft_strequ(ent->name, "..")))
		{
			write(1, "\n", 1);
			conf->multiple_targets = TRUE;
			if ((subpath = fs_join(path, ent->name)) != NULL)
				ls_list(subpath, conf);
			else
				// TODO
				PASS;
			free(subpath);
		}
}
