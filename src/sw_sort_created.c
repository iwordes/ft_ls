/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_sort_created.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:08:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 18:05:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sw_sort_created(t_ls *config)
{
	#ifdef _DARWIN_FEATURE_64_BIT_INODE
	config->order = order_created;
	config->time = time_created;
	#endif
}
