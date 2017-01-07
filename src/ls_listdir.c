/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:08:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 10:51:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_ent	**panic_(char **child, t_ent **ent, unsigned l)
{
	unsigned	i;

	i = 0;
	while (i < l)
		free(child[i++]);
	free(child);
	i = 0;
	while (i < l && ent[i] != NULL)
		free(ent[i++]);
	free(ent);
	return (NULL);
}

static char		name_qualifies_(char *name, t_ls *conf)
{
	if (!conf->show_all && ((!conf->show_hidden && child[i][0] == '.')
		|| (ft_strequ(child[i], ".") || ft_strequ(child[i], ".."))))
		return (FALSE);
	return (TRUE);
}

/*
** Return a t_ent[] of the contents of the given directory path.
** Does not return any entry that should not be included.
*/
/*
** TODO: Handle non-directories gracefully
** TODO: Malloc less space if not necessary
*/

t_ent			**ls_listdir(const char *path, t_ls *conf)
{
	char			**child;
	t_ent			**ent;
	unsigned		i;
	unsigned		l;

	NULL_GUARD(child = fs_listdir(path));
	l = 0;
	i = ~0;
	while (child[(i += 1)] != NULL)
		if (name_qualifies_(child[i], conf))
			l += 1;
	if ((ent = (t_ent**)malloc(sizeof(void*) * (l + 1))) == NULL)
		return (panic_(child, ent, l));
	i = 0;
	while (i < l)
	{
		if (!name_qualifies_(child[i], conf))
			free(child[i]);
		else if ((ent[i] = ls_create_ent(path, child[i], conf)) == NULL)
			return (panic_(child, ent, l));
		i += 1;
	}
	free(child);
	ent[l] = NULL;
	return (ent);
}
