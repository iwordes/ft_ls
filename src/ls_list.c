/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:54:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 20:16:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	_cleanup(t_ent **ent);

/*
** List the contents of a directory, and if applicable, all subdirectories.
*/
/*
** Potential optimizations:
** - Reduce the number of malloc/free calls by using a list(-like) struct OR
**   by using a dirent**.
*/

void	ls_list(const char *path, t_ls *conf)
{
	char			*subpath;
	t_ent			**ent;
	unsigned		i;

	if ((ent = ls_listdir(path, conf)) == NULL)
		// TODO: deal with this
		exit(0x48414C50);
	ls_table_sort(ent, order_name, FALSE);
	if (conf->multiple_targets)
		ft_printf("%s:\n", path);
	ls_table_fmt(path, ent, conf);
	if (conf->recurse)
	{
		!(ent[0] == NULL || ent[2] == NULL) && write(1, "\n", 1);
		i = (unsigned)-1;
		while (ent[(i += 1)] != NULL)
		{
			if (ft_strequ(ent[i]->name, ".") || ft_strequ(ent[i]->name, "..")
				|| !S_ISDIR(ent[i]->info.st_mode))
				continue ;
			conf->multiple_targets = TRUE;
			if ((subpath = fs_join(path, ent[i]->name)) != NULL)
				ls_list(subpath, conf);
			else
				// TODO
				PASS;
			free(subpath);
			// If this is not the last entry, write a newline.
			// NOTE: Will not work in every case. (e.g. next should be ignored)
			(ent[i + 1] != NULL) && write(1, "\n", 1);
		}
	}
	_cleanup(ent);
}

static void	_cleanup(t_ent **ent)
{
	unsigned	i;

	i = 0;
	while (ent[i] != NULL)
	{
		free(ent[i]);
		i += 1;
	}
	free(ent);
}
