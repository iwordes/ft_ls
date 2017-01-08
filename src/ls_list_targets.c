/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 13:01:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_ent	**eft_panic_(t_ent **targets, unsigned l)
{
	unsigned	i;

	i = 0;
	while (i < l)
		free(targets[i++]);
	free(targets);
	return (NULL);
}

static t_ent	**ents_from_targets(char **raw, unsigned l, t_ls *conf)
{
	t_ent		**ent;
	unsigned	i;

	i = 0;
	NULL_GUARD(ent = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	while (i < l)
	{
		if ((ent[i] = ls_create_ent("", ft_strdup(raw[i]), conf)) == NULL)
			return (eft_panic_(ent, i));
		i += 1;
	}
	ent[l] = NULL;
	return (ent);
}

static void		determine_pad_(t_ent **ent, t_lspad *pad, t_ls *conf)
{
	unsigned	i;

	i = ~0;
	ft_bzero(pad, sizeof(t_lspad));
	while (ent[(i += 1)] != NULL)
	{
		if (!S_ISREG(ent[i]->info.st_mode))
			continue ;
		pad->inode = MAX(pad->inode, ft_intlen(ent[i]->info.st_ino));
		pad->mode = MAX(pad->mode, ft_strlen(ls_fmt_mode(ent[i])));
		pad->nlinks = MAX(pad->nlinks, ft_strlen(
			ls_fmt_nlinks(ent[i]->info.st_nlink)));
		pad->user = MAX(pad->user, ft_strlen(
			ls_fmt_user(ent[i]->info.st_uid)));
		pad->group = MAX(pad->group, ft_strlen(
			ls_fmt_group(ent[i]->info.st_gid)));
		pad->size = MAX(pad->size, ft_intlen(ent[i]->info.st_size));
		pad->timeyear = MAX(pad->timeyear, ft_strlen(
			ls_fmt_timeyear(ls__propertime(ent[i], conf))));
	}
	pad->timeyear = MAX(pad->timeyear, 5);
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
		ls_list(dir[i]->name, conf);
	}
	i = ~0;
	while (dir[i += 1] != NULL)
		free(dir[i]);
}

static void	lfile__(t_ent **file, t_ent **table, t_ls *conf)
{
	unsigned	f;
	unsigned	i;
	t_lspad		pad;

	f = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		if (!S_ISDIR(table[i]->info.st_mode))
			file[f++] = table[i];
	file[f] = NULL;
	ls_table_sort(file, conf->order, conf->sort_rev);
	if (conf->detailed)
		determine_pad_(file, &pad, conf);
	i = ~0;
	while (file[i += 1] != NULL)
		if (conf->detailed)
			ls_ent_print_detailed(file[i], &pad, conf);
		else
			ft_printf("%s\n", file[i]->name);
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

	LS_MALLOCERR(table = ents_from_targets(targets, t, conf));
	l = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		(!S_ISDIR(table[i]->info.st_mode)) && (l += 1);
	LS_MALLOCERR(file = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	lfile__(file, table, conf);
	(l > 0) && write(1, "\n", 1);
	l = 0;
	i = ~0;
	while (table[i += 1] != NULL)
		(S_ISDIR(table[i]->info.st_mode)) && (l += 1);
	LS_MALLOCERR(dir = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	ldir__(dir, table, conf);
	free(dir);
	free(file);
	free(table);
}
/*
{
	t_ent		**ent;
	t_lspad		pad;
	unsigned	i;

	if ((ent = ents_from_targets(targets, t, conf)) == NULL)
		exit(LS_ERR_MALLOC);
	ls_table_sort(ent, conf->order, conf->sort_rev);
	ls_table_sort_adv()
	determine_pad_(ent, &pad, conf);
	i = ~0;
	while (ent[(i += 1)] != NULL)
	{
		if (S_ISDIR(ent[i]->info.st_mode))
			continue ;
		conf->ltargets__hasfile = TRUE;
		if (conf->detailed)
			ls_ent_print_detailed(ent[i], &pad, conf);
		else
			ft_printf("%s\n", ent[i]->name);
	}
	i = ~0;
	while (ent[(i += 1)] != NULL)
	{
		if (!S_ISDIR(ent[i]->info.st_mode))
			continue ;
		(i != 0 || conf->ltargets__hasfile) && write(1, "\n", 1);
		ls_list(ent[i]->name, conf);
	}
	free(ent);
}
*/
