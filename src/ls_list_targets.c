/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 19:26:40 by iwordes          ###   ########.fr       */
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
	// TODO: Dynamic sorting here
	ls__sort(ent, sort_name, FALSE);
	return (ent);
}

static void		determine_pad_(t_ent **ent, t_lspad *pad, t_ls *conf)
{
	unsigned	i;

	pad->inode = 0;
	pad->mode = 0;
	pad->user = 0;
	pad->group = 0;
	pad->size = 0;
	i = (unsigned)-1;
	while (ent[(i += 1)] != NULL)
	{
		if (!S_ISREG(ent[i]->info.st_mode))
			continue ;
		if (!conf->show_all
			&& (ft_strequ(ent[i]->name, ".") || ft_strequ(ent[i]->name, "..")))
			continue ;
		if (!(conf->show_all || conf->show_hidden) && ent[i]->name[0] == '.')
			continue ;
		pad->inode = MAX(pad->inode, ft_intlen(ent[i]->info.st_ino));
		pad->mode = MAX(pad->mode, ft_strlen(ls_fmt_mode(ent[i])));
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

void	ls_list_targets(char **targets, unsigned tgt_cnt, t_ls *conf)
{
	t_ent		**ent;
	t_lspad		pad;
	unsigned	i;

	if ((ent = ents_from_targets(targets, tgt_cnt, conf)) == NULL)
		exit(1);
	i = ~0;
	determine_pad_(ent, &pad, conf);
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
		ls_list(ent[i]->name, conf);
	}
	free(ent);
}
