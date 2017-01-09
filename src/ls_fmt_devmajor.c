/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_devmajor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:42:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 10:44:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_devmajor(t_ent *ent)
{
	static char	buffer[23];

	if (!S_ISBLK(ent->info.st_mode) && !S_ISCHR(ent->info.st_mode))
		return ("");
	buffer[0] = ' ';
	ls__naitoa(buffer + 1, major(ent->info.st_rdev));
	ft_strcat(buffer, ", ");
	return (buffer);
}
