/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_changed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:23:34 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 16:38:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sw_sort_changed(t_ls *conf)
{
	if (conf->do_sort && conf->order != sort_size)
		conf->order = sort_changed;
	conf->order_cache = sort_changed;
	conf->time = time_changed;
}
