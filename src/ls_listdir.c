/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:08:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 19:34:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_ent	**_panic(char **child, t_ent **ent, unsigned l)
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

/*
** Return a t_ent[] of the contents of the given directory path.
*/

t_ent			**ls_listdir(const char *path)
{
	char			**child;
	t_ent			**ent;
	unsigned		i;
	unsigned		l;

	NULL_GUARD(child = fs_listdir(path));
	if ((l = fs_dirlen(path)) == (unsigned)-1)
		return (NULL);
	if ((ent = (t_ent**)malloc(sizeof(void*) * (l + 1))) == NULL)
		return (_panic(child, ent, l));
	i = 0;
	while (i < l)
	{
		if ((ent[i] = ls_create_ent(path, child[i])) == NULL)
			return (_panic(child, ent, l));
		i += 1;
	}
	free(child);
	ent[l] = NULL;
	return (ent);
}
