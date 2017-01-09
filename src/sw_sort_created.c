/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_created.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:08:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 16:36:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sw_sort_created(t_ls *config)
{
	if (config->do_sort && config->order != sort_size)
		config->order = sort_created;
	config->order_cache = sort_created;
	config->time = time_created;
}
