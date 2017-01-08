/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_accessed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:28:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 13:49:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Sort by time of last access.
*/

long	sort_accessed(t_ent *e1, t_ent *e2)
{
	if (e1->info.st_atimespec.tv_sec != e2->info.st_atimespec.tv_sec)
		return (e1->info.st_atimespec.tv_sec - e2->info.st_atimespec.tv_sec);
	return (e1->info.st_atimespec.tv_nsec - e2->info.st_atimespec.tv_nsec);
}
