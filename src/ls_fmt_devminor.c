/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_devminor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:31:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 10:52:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_devminor(t_ent *ent)
{
	static char	buffer[20];

	ls__naitoa(buffer, minor(ent->info.st_rdev));
	return (buffer);
}
