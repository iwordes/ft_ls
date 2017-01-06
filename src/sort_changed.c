/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_changed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:50:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 18:07:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		sort_changed(t_ent *e1, t_ent *e2)
{
	if (e1->info.st_ctimespec.tv_sec != e2->info.st_ctimespec.tv_sec)
		return (e1->info.st_ctimespec.tv_sec - e2->info.st_ctimespec.tv_sec);
	return (e1->info.st_ctimespec.tv_nsec - e2->info.st_ctimespec.tv_nsec);
}
