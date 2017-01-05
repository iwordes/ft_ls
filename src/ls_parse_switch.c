/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_switch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:51:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/03 18:21:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*g_swc =
	"AR" "lrt";

static void	(*g_swf[])(t_ls*) =
{
	sw_show_hidden,
	sw_recursive,

	sw_show_dot,
	sw_long_format,
	sw_sort_reverse,
	sw_sort_modified,
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

	// DEBUG
	printf("%c", sw);

	g_swf[i](config);
	return (TRUE);
}
