/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls__propertime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:28:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 09:29:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

time_t	ls__propertime(t_ent *ent, t_ls *conf)
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
