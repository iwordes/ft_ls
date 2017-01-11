/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_islink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:12:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 15:13:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfs.h>

char	fs_islink(const char *path)
{
	t_stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	return (S_ISLNK(buffer.st_mode));
}
