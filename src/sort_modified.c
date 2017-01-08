/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_modified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 10:26:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long	sort_modified(t_ent *e1, t_ent *e2)
{
	if (e1->info.st_mtimespec.tv_sec != e2->info.st_mtimespec.tv_sec)
		return (e1->info.st_mtimespec.tv_sec - e2->info.st_mtimespec.tv_sec);
	return (e1->info.st_mtimespec.tv_nsec - e2->info.st_mtimespec.tv_nsec);
}
