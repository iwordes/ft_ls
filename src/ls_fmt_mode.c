/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:19:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 15:17:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	type_(mode_t mode, char buffer[11])
{
	if (S_ISREG(mode))
		buffer[0] = '-';
	else if (S_ISBLK(mode))
		buffer[0] = 'b';
	else if (S_ISCHR(mode))
		buffer[0] = 'c';
	else if (S_ISDIR(mode))
		buffer[0] = 'd';
	else if (S_ISLNK(mode))
		buffer[0] = 'l';
	else if (S_ISFIFO(mode))
		buffer[0] = 'p';
	else if (S_ISSOCK(mode))
		buffer[0] = 's';
	else
		buffer[0] = '?';
}

static void	owner_(mode_t mode, char buffer[11])
{
	buffer[1] = (mode & 0400) ? 'r' : '-';
	buffer[2] = (mode & 0200) ? 'w' : '-';
	if (mode & 04000)
		buffer[3] = (mode & 0100) ? 's' : 'S';
	else
		buffer[3] = (mode & 0100) ? 'x' : '-';
}

static void	group_(mode_t mode, char buffer[11])
{
	buffer[4] = (mode & 0040) ? 'r' : '-';
	buffer[5] = (mode & 0020) ? 'w' : '-';
	if (mode & 02000)
		buffer[6] = (mode & 0010) ? 's' : 'S';
	else
		buffer[6] = (mode & 0010) ? 'x' : '-';
}

static void	other_(mode_t mode, char buffer[11])
{
	buffer[7] = (mode & 0004) ? 'r' : '-';
	buffer[8] = (mode & 0002) ? 'w' : '-';
	if (mode & 01000)
		buffer[9] = (mode & 0001) ? 't' : 'T';
	else
		buffer[9] = (mode & 0001) ? 'x' : '-';
}

const char	*ls_fmt_mode(t_ent *ent)
{
	static char	buffer[12];

	type_(ent->info.st_mode, buffer);
	owner_(ent->info.st_mode, buffer);
	group_(ent->info.st_mode, buffer);
	other_(ent->info.st_mode, buffer);
	buffer[10] = (ent->has_xattr) ? '@' : 0;
	return (buffer);
}
