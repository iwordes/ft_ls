/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 18:46:17 by iwordes          ###   ########.fr       */
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

static void		determine_pad_(t_ent **ent, t_lspad *pad)
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
	}
}

/*
** Iterate over each target, formatting a table from the files and printing it,
** then iterating over each directory and listing its contents.
**
** If conf->recurse is enabled, print all subdirectories, too.
*/

void	ls_list_targets(char **targets, unsigned t, t_ls *conf)
{
	t_ent		**ent;
	t_lspad		pad;
	unsigned	i;

	if ((ent = ents_from_targets(targets, t, conf)) == NULL)
		exit(LS_ERR_MALLOC);
	ls_table_sort(ent, conf->order, conf->sort_rev);
	determine_pad_(ent, &pad);
	i = ~0;
	while (ent[(i += 1)] != NULL)
	{
		if (S_ISDIR(ent[i]->info.st_mode))
			continue ;
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
		(i != 0) && write(1, "\n", 1);
		ls_list(ent[i]->name, conf);
	}
	free(ent);
}
