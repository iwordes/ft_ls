/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:40:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 15:39:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	err_list(const char *path)
{
	size_t	i;

	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i -= 1;
	if (path[i] == '/')
		i += 1;
	ft_printf("ls: %s: %s\n", path + i, strerror(errno));
	g_exit = 1;
	return (1);
}
