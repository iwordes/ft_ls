/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_changed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:50:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:00:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define TIMEOF(E) E->info.st_ctimespec

long	sort_changed(t_ent *e1, t_ent *e2)
{
	if (TIMEOF(e1).tv_sec != TIMEOF(e2).tv_sec)
		return (TIMEOF(e1).tv_sec - TIMEOF(e2).tv_sec);
	return (TIMEOF(e1).tv_nsec - TIMEOF(e2).tv_nsec);
}
