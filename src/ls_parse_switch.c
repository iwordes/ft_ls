/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_switch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:51:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 16:10:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*g_swc =
	"ARSU" "ailrtu";

static void	(*g_swf[])(t_ls*) =
{
	sw_show_hidden,
	sw_recursive,
	sw_sort_size,
	sw_sort_created,

	sw_show_all,
	sw_show_inode,
	sw_long_format,
	sw_sort_reverse,
	sw_sort_modified,
	sw_sort_accessed,
	NULL
};

char		ls_parse_switch(char sw, t_ls *config)
{
	int		i;

	i = 0;
	while (sw != g_swc[i] && g_swc[i] != 0)
		i++;
	if (g_swc[i] == 0 || g_swf[i] == NULL)
		return (FALSE);
	g_swf[i](config);
	return (TRUE);
}
