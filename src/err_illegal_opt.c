/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_illegal_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:20:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/16 09:40:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	err_illegal_opt(const char *path, char opt)
{
	ft_eprintf("%s: illegal option -- %c\n", path, opt);
	ft_eprintf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] "
				"[file ...]\n");
	exit(1);
}
