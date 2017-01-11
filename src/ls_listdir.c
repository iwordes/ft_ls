/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:08:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 19:17:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		name_qualifies_(char *name, t_ls *conf)
{
	if (!conf->show_all && ((!conf->show_hidden && name[0] == '.')
		|| (ft_strequ(name, ".") || ft_strequ(name, ".."))))
		return (FALSE);
	return (TRUE);
}

/*
** Return a table of the contents of the given directory path.
** Does not return any entry that should not be included.
*/
/*
** Might be optimized by not spending logic time to allocate less memory for
** the entire table.
*/

t_ent			**ls_listdir(const char *path, t_ls *conf)
{
	char			**child;
	t_ent			**table;
	unsigned		i;
	unsigned		l;

	NULL_GUARD(child = fs_listdir(path));
	l = 0;
	i = ~0;
	while (child[i += 1] != NULL)
		if (name_qualifies_(child[i], conf))
			l += 1;
	LS_MGUARD(table = (t_ent**)malloc(sizeof(void*) * (l + 1)));
	l = 0;
	i = ~0;
	while (child[i += 1] != NULL)
		if (!name_qualifies_(child[i], conf))
			free(child[i]);
		else
			LS_MGUARD(table[l++] = ls_create_ent(path, child[i]));
	table[l] = NULL;
	free(child);
	return (table);
}
