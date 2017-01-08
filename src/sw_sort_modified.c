/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:05:44 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 13:42:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sw_sort_modified(t_ls *config)
{
	if (!config->do_sort)
		config->order = sort_modified;
	if (config->order_cache != NULL)
		config->order = config->order_cache;
	config->do_sort = TRUE;
}
