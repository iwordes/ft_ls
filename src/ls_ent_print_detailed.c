/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ent_print_detailed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:18:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 10:52:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			ls_ent_print_detailed(t_ent *ent, t_lspad *pad, t_ls *conf)
{
	time_t	t;

	t = ls__propertime(ent, conf);
	if (conf->show_inode)
		ft_printf("%-*s ", pad->inode, ls_fmt_inode(ent->info.st_ino));
	ft_printf("%-11s %*s %-*s  %-*s  %*s%*s %s %*s %s\n",
		ls_fmt_mode(ent),
		pad->nlinks, ls_fmt_nlinks(ent->info.st_nlink),
		pad->user, ls_fmt_user(ent->info.st_uid),
		pad->group, ls_fmt_group(ent->info.st_gid),
		pad->devmajor, ls_fmt_devmajor(ent),
		pad->size, ls_fmt_size(ent),
		ls_fmt_date(t), pad->timeyear, ls_fmt_timeyear(t),
		ls_fmt_name(ent, conf));
}
