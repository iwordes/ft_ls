/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_changed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:50:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 13:49:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long	sort_changed(t_ent *e1, t_ent *e2)
{
	if (e1->info.st_ctimespec.tv_sec != e2->info.st_ctimespec.tv_sec)
		return (e1->info.st_ctimespec.tv_sec - e2->info.st_ctimespec.tv_sec);
	return (e1->info.st_ctimespec.tv_nsec - e2->info.st_ctimespec.tv_nsec);
}
