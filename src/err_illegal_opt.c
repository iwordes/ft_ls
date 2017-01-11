/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_illegal_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:20:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/11 12:26:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	err_illegal_opt(char opt)
{
	ft_printf("%s: illegal option -- %c\n", g_name, opt);
	ft_printf("usage: ls [-AGRSUacilrtu1] [file ...]\n");
	exit(1);
}
