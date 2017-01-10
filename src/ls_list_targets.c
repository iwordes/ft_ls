/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 13:53:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define VALDIR__1(E) LS_ISDIR(E)
#define VALDIR__2(E) (!conf->detailed && LS_ISLNK(E) && fs_isdir(E->qual_link))
#define VALID_DIR(ENT) (VALDIR__1(ENT) || VALDIR__2(ENT))

static t_ent	**ents_from_targets(char **raw, unsigned l, t_ls *conf)
{
	char		*basename;
	char		*dirname;
	t_ent		**table;
	unsigned	col;
	unsigned	i;

	i = ~0;
	col = 0;
	LS_MGUARD(table = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	while ((i += 1) < l)
	{
		LS_MGUARD(dirname = fs_dirname(raw[i]));
		LS_MGUARD(basename = fs_basename(raw[i]));
		if ((table[col++] = ls_create_ent(dirname, basename, conf)) == NULL)
			(col--) && err_path(raw[i]);
		else
			LS_MGUARD(table[col - 1]->name = ft_strdup(raw[i]));
		free(basename);
		free(dirname);
	}
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
		if (VALID_DIR(table[i]))
			dir[d++] = table[i];
	dir[d] = NULL;
	ls_table_sort(dir, sort_name, FALSE);
	i = ~0;
	while (dir[i += 1] != NULL)
	{
		(i != 0) && write(1, "\n", 1);
		if (!LS_ISLNK(dir[i]))
			ls_list(dir[i]->name, conf) || err_list(dir[i]->name);
		else
			ls_list(dir[i]->qual_link, conf) || err_list(dir[i]->name);
	}
}

static void	lfile__(t_ent **file, t_ent **table, t_ls *conf)
{
	unsigned	f;
	unsigned	i;
	t_lspad		pad;

	f = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		if (!VALID_DIR(table[i]))
			file[f++] = table[i];
	file[f] = NULL;
	ls_table_sort(file, conf->order, conf->sort_rev);
	ls_table_sort_adv(file, conf->order, sort_name, conf->sort_rev);
	ls_table_align(file);
	ls__genpad(file, &pad, conf);
	i = ~0;
	if (conf->detailed)
		while (file[i += 1] != NULL)
			ls_ent_print_detailed(file[i], &pad, conf);
	else
		while (file[i += 1] != NULL)
			ft_printf("%s\n", file[i]->name);
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
		if (!VALID_DIR(table[i]))
			l += 1;
	LS_MGUARD(file = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	lfile__(file, table, conf);
	l = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		if (VALID_DIR(table[i]))
			l += 1;
	LS_MGUARD(dir = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	(l > 0 && file[0] != NULL) && write(1, "\n", 1);
	ldir__(dir, table, conf);
	ls_destroy_table(file);
	ls_destroy_table(dir);
	free(table);
}
