/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:29:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 18:30:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
**
*/

static void	_detailed_total(t_ent **ent, t_ls *conf)
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

static void	_detailed_pad(t_ent **ent, t_lspad *pad)
{
	(void)ent;
	(void)pad;
}

void	_detailed_print(t_ent **ent, t_ls *conf)
{
	unsigned	i;
	t_lspad		pad;

	_detailed_total(ent, conf);
	_detailed_pad(ent, &pad);
	i = (unsigned)-1;
	while (ent[(i += 1)] != NULL)
	{
		if (!conf->show_all && (ft_strequ(ent[i]->name, ".")
			|| ft_strequ(ent[i]->name, "..")))
			continue ;
		if (!conf->show_hidden && ent[i]->name[0] == '.')
			continue;
		if (conf->show_inode)
			ft_printf("%s ", ls_fmt_inode(ent[i]->info.st_ino));
		ft_printf("%s %2d %8s %8s %8s %.12s %s\n",
			ls_fmt_mode(ent[i]->info.st_mode), ent[i]->info.st_nlink,
			ls_fmt_user(ent[i]->info.st_uid), ls_fmt_group(ent[i]->info.st_gid),
			ls_fmt_size(ent[i]->info.st_size),
			ctime(&ent[i]->info.st_mtimespec.tv_sec) + 4, ent[i]->name
		);
	}
}

void	_simple_print(t_ent **ent, t_ls *conf)
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
		_detailed_print(ent, conf);
	else
		_simple_print(ent, conf);
}
