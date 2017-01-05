/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_illegal_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:20:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/03 18:03:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	err_illegal_opt(const char *bin, char opt)
{
	ft_printf("%s: illegal option -- %c\n", bin, opt);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file...]\n");
	exit(1);
}
