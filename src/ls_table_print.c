/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:29:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 15:55:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	detailed_total_(t_ent **ent, t_ls *conf)
{
	uintmax_t	total;
	unsigned	i;

	i = (unsigned)-1;
	total = 0;
	while (ent[(i += 1)] != NULL)
	{
		if (!conf->show_all
			&& (ft_strequ(ent[i]->name, ".") || ft_strequ(ent[i]->name, "..")))
			continue ;
		if (!(conf->show_all || conf->show_hidden) && ent[i]->name[0] == '.')
			continue ;
		total += ent[i]->info.st_blocks;
	}
	ft_printf("total %ju\n", total);
}

/*
** Potential TODO: Dynamic padding for nlinks
*/

static void	detailed_pad_(t_ent **ent, t_lspad *pad, t_ls *conf)
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

void	detailed_print_(t_ent **ent, t_ls *conf)
{
	unsigned	i;
	t_lspad		pad;

	if (ent[0] != NULL && ent[1] != NULL && ent[2] != NULL)
		detailed_total_(ent, conf);
	detailed_pad_(ent, &pad, conf);
	i = ~0;
	while (ent[(i += 1)] != NULL)
	{
		if (!conf->show_all
			&& (ft_strequ(ent[i]->name, ".") || ft_strequ(ent[i]->name, "..")))
			continue ;
		if (!(conf->show_all || conf->show_hidden) && ent[i]->name[0] == '.')
			continue ;
		ls_ent_print_detailed(ent[i], &pad, conf);
	}
}

/*
** TODO: Print columns
*/

void	simple_print_(t_ent **ent, t_ls *conf)
{
	unsigned	i;

	i = (unsigned)-1;
	while (ent[(i += 1)] != NULL)
	{
		if (!conf->show_all && (ft_strequ(ent[i]->name, ".")
			|| ft_strequ(ent[i]->name, "..")))
			continue ;
		if (!conf->show_hidden && ent[i]->name[0] == '.')
			continue;
		ft_printf("%s\n", ent[i]->name);
	}
}

void	ls_table_print(t_ent **ent, t_ls *conf)
{
	if (conf->detailed)
		detailed_print_(ent, conf);
	else
		simple_print_(ent, conf);
}
