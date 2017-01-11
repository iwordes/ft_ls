/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_modified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:00:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define TIMEOF(E) E->info.st_mtimespec

long	sort_modified(t_ent *e1, t_ent *e2)
{
	if (TIMEOF(e1).tv_sec != TIMEOF(e2).tv_sec)
		return (TIMEOF(e1).tv_sec - TIMEOF(e2).tv_sec);
	return (TIMEOF(e1).tv_nsec - TIMEOF(e2).tv_nsec);
}
