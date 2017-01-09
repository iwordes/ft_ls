/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_accessed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:07:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 16:36:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sw_sort_accessed(t_ls *config)
{
	if (config->do_sort && config->order != sort_size)
		config->order = sort_accessed;
	config->order_cache = sort_accessed;
	config->time = time_accessed;
}
