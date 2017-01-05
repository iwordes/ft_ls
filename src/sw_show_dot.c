/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_show_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:35:26 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/04 12:36:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Show all files beginning with a dot, including "." and "..".
*/

void	sw_show_dot(t_ls *config)
{
	config->show_dot = TRUE;
}
