/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_created.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 13:49:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long	sort_created(t_ent *e1, t_ent *e2)
{
	if (e1->info.st_birthtimespec.tv_sec != e2->info.st_birthtimespec.tv_sec)
		return (e1->info.st_birthtimespec.tv_sec
			- e2->info.st_birthtimespec.tv_sec);
	return (e1->info.st_birthtimespec.tv_nsec
		- e2->info.st_birthtimespec.tv_nsec);
}
