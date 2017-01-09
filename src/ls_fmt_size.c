/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:26:29 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 10:46:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_size(t_ent *ent)
{
	static char	buffer[20];

	if (S_ISBLK(ent->info.st_mode) || S_ISCHR(ent->info.st_mode))
		return (ls_fmt_devminor(ent));
	ls__naitoa(buffer, ent->info.st_size);
	return (buffer);
}
