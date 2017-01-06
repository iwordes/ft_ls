/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_created.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 18:04:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		sort_created(t_ent *e1, t_ent *e2)
{
	#ifdef _DARWIN_FEATURE_64_BIT_INODE
	if (e1->info.st_birthtimespec.tv_sec != e2->info.st_birthtimespec.tv_sec)
		return (e1->info.st_ctimespec.tv_sec
				- e2->info.st_ctimespec.tv_sec);
	return (e1->info.st_birthtimespec.tv_nsec
			- e2->info.st_birthtimespec.tv_nsec);
	#else
	return (0);
	#endif
}
