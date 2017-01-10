/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:46 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 10:15:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		ansii_tag_(mode_t mode, char buffer[1024])
{
	if (S_ISDIR(mode) && !(mode & 002))
		ft_strcpy(buffer, "\e[34m");
	else if (S_ISDIR(mode))
		ft_strcpy(buffer, (mode & 01000) ? "\e[30;42m" : "\e[30;43m");
	else if (S_ISLNK(mode))
		ft_strcpy(buffer, "\e[35m");
	else if (S_ISCHR(mode))
		ft_strcpy(buffer, "\e[34;43m");
	else if (S_ISSOCK(mode))
		ft_strcpy(buffer, "\e[32m");
	else if (S_ISFIFO(mode))
		ft_strcpy(buffer, "\e[33m");
	else if (S_ISREG(mode) && (mode & 111) && !(mode & 06000))
		ft_strcpy(buffer, "\e[31m");
	else if (S_ISREG(mode) && (mode & 111) && (mode & 06000))
		ft_strcpy(buffer, (mode & 04000) ? "\e[30;41m" : "\e[30;46m");
	else
		return (FALSE);
	return (TRUE);
}

const char		*ls_fmt_name(t_ent *ent, t_ls *conf)
{
	static char	buffer[2048];
	char		color;

	if (!conf->colorize && ent->raw_link == NULL)
		return (ent->name);
	color = FALSE;
	buffer[0] = 0;
	if (conf->colorize)
		color = ansii_tag_(ent->info.st_mode, buffer);
	ft_strcat(buffer, ent->name);
	if (color)
		ft_strcat(buffer, "\e[0m");
	if (conf->detailed && ent->raw_link != NULL)
	{
		ft_strcat(buffer, " -> ");
		ft_strcat(buffer, ent->raw_link);
	}
	return (buffer);
}
