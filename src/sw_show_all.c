/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_show_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:35:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:29:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Show all files beginning with a dot, including "." and "..".
*/

void	sw_show_all(t_ls *config)
{
	config->show_all = TRUE;
	config->show_hidden = TRUE;
}
