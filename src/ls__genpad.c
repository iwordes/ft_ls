/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls__genpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:50:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 16:54:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ls__genpad(t_ent **ent, t_lspad *pad, t_ls *conf)
{
	unsigned	i;

	i = ~0;
	ft_bzero(pad, sizeof(t_lspad));
	while (ent[(i += 1)] != NULL)
	{
		pad->inode = MAX(pad->inode, ft_intlen(ent[i]->info.st_ino));
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
