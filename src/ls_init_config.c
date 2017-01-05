/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 09:59:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/03 14:17:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ls_init_config(t_ls *config)
{
	ft_bzero(config, sizeof(t_ls));
	/*config->detail = FALSE;
	config->one_col = TRUE;
	config->recurse = FALSE;
	config->show_dot = FALSE;
	config->show_hid = FALSE;*/
}
