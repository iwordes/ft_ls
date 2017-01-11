/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_accessed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:28:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 18:59:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define TIMEOF(E) E->info.st_atimespec

long	sort_accessed(t_ent *e1, t_ent *e2)
{
	if (TIMEOF(e1).tv_sec != TIMEOF(E2).tv_sec)
		return (TIMEOF(e1).tv_sec - TIMEOF(e2).tv_sec);
	return (TIMEOF(e1).tv_nsec - TIMEOF(e2).tv_nsec);
}
