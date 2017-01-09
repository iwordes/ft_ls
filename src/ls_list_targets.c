/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 15:54:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_ent	**ents_from_targets(char **raw, unsigned l, t_ls *conf)
{
	t_ent		**table;
	unsigned	col;
	unsigned	i;

	i = ~0;
	col = 0;
	LS_MGUARD(table = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	while ((i += 1) < l)
		if ((table[col++] = ls_create_ent("", ft_strdup(raw[i]), conf)) == NULL)
			(col--) && err_path(raw[i]);
	table[col] = NULL;
	return (table);
}

/*
** Iterate over each target, formatting a table from the files and printing it,
** then iterating over each directory and listing its contents.
**
** If conf->recurse is enabled, print all subdirectories, too.
*/

static void	ldir__(t_ent **dir, t_ent **table, t_ls *conf)
{
	unsigned	d;
	unsigned	i;

	d = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		if (S_ISDIR(table[i]->info.st_mode))
			dir[d++] = table[i];
	dir[d] = NULL;
	ls_table_sort(dir, sort_name, FALSE);
	i = ~0;
	while (dir[i += 1] != NULL)
	{
		(i != 0) && write(1, "\n", 1);
		ls_list(dir[i]->name, conf) || err_list(dir[i]->name);
	}
	i = ~0;
	while (dir[i += 1] != NULL)
		free(dir[i]);
}

static void	lfile__(t_ent **file, t_ent **table, t_ls *conf)
{
	unsigned	f;
	unsigned	i;

	f = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		if (!S_ISDIR(table[i]->info.st_mode))
			file[f++] = table[i];
	file[f] = NULL;
	ls_table_sort(file, conf->order, conf->sort_rev);
	ls_table_fmt(NULL, file, conf);
	i = ~0;
	while (file[i += 1] != NULL)
		free(file[i]);
}

void	ls_list_targets(char **targets, unsigned t, t_ls *conf)
{
	t_ent		**table;
	t_ent		**file;
	t_ent		**dir;
	unsigned	i;
	unsigned	l;

	LS_MGUARD(table = ents_from_targets(targets, t, conf));
	l = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		(!S_ISDIR(table[i]->info.st_mode)) && (l += 1);
	LS_MGUARD(file = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	lfile__(file, table, conf);
	l = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		(S_ISDIR(table[i]->info.st_mode)) && (l += 1);
	LS_MGUARD(dir = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	(l > 0 && file[0] != NULL) && write(1, "\n", 1);
	ldir__(dir, table, conf);
	free(dir);
	free(file);
	free(table);
}
