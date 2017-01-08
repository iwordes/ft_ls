/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:29:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 09:49:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	detailed_total_(t_ent **ent)
{
	uintmax_t	total;
	unsigned	i;

	i = ~0;
	total = 0;
	while (ent[(i += 1)] != NULL)
		total += ent[i]->info.st_blocks;
	ft_printf("total %ju\n", total);
}

/*
** Potential TODO: Dynamic padding for nlinks
*/
/*
** Opt: This function may be causing a good chunk of delay.
*/

static void	detailed_pad_(t_ent **ent, t_lspad *pad, t_ls *conf)
{
	unsigned	i;

	i = ~0;
	ft_bzero(pad, sizeof(t_lspad));
	while (ent[(i += 1)] != NULL)
	{
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

void		ls_table_print(t_ent **ent, t_ls *conf)
{
	unsigned	i;
	t_lspad		pad;

	i = 0;
	if (!conf->detailed)
		while (ent[i] != NULL)
			ft_printf("%s\n", ls_fmt_name(ent[i++], conf));
	else
	{
		if (ent[0] != NULL)
			detailed_total_(ent);
		detailed_pad_(ent, &pad, conf);
		while (ent[i] != NULL)
			ls_ent_print_detailed(ent[i++], &pad, conf);
	}
}
