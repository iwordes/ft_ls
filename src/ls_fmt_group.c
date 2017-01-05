/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:15:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:59:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_group(gid_t gid)
{
	static char		buffer[20];
	struct group	*group;

	if ((group = getgrgid(gid)) != NULL)
		return (group->gr_name);
	ls__naitoa(buffer, gid);
	return (buffer);
}
