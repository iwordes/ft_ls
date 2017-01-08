/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ent_print_detailed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:18:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 18:59:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static time_t	time__(t_ent *ent, t_ls *conf)
{
	if (conf->time == time_modified)
		return (ent->info.st_mtimespec.tv_sec);
	else if (conf->time == time_accessed)
		return (ent->info.st_atimespec.tv_sec);
	else if (conf->time == time_changed)
		return (ent->info.st_ctimespec.tv_sec);
	else if (conf->time == time_created)
		return (ent->info.st_birthtimespec.tv_sec);
	else
		return (ent->info.st_mtimespec.tv_sec);
}

void			ls_ent_print_detailed(t_ent *ent, t_lspad *pad, t_ls *conf)
{
	time_t	t;

	t = time__(ent, conf);
	if (conf->show_inode)
		ft_printf("%-*s ", pad->inode, ls_fmt_inode(ent->info.st_ino));
	ft_printf("%-*s  %*s %*s  %*s  %*s %.12s %s\n",
		pad->mode, ls_fmt_mode(ent),
		pad->nlinks, ls_fmt_nlinks(ent->info.st_nlink),
		pad->user, ls_fmt_user(ent->info.st_uid),
		pad->group, ls_fmt_group(ent->info.st_gid),
		pad->size, ls_fmt_size(ent->info.st_size),
		ctime(&t) + 4,
		ls_fmt_name(ent, conf));
}
