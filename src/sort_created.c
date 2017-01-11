/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_created.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:00:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define TIMEOF(E) E->info.st_birthtimespec

long	sort_created(t_ent *e1, t_ent *e2)
{
	if (TIMEOF(e1).tv_sec != TIMEOF(e2).tv_sec)
		return (TIMEOF(e1).tv_sec - TIMEOF(e2).tv_sec);
	return (TIMEOF(e1).tv_nsec - TIMEOF(e2).tv_nsec);
}
