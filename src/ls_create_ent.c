/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 16:47:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ent	*ls_create_ent(const char *path, char *child)
{
	char	*qual_path;
	t_ent	*ent;

	NULL_GUARD(path);
	NULL_GUARD(child);
	NULL_GUARD(ent = (t_ent*)malloc(sizeof(t_ent)));
	if ((qual_path = fs_join(path, child)) == NULL)
	{
		free(ent);
		return (NULL);
	}
	if (lstat(qual_path, &ent->info) != 0)
	{
		free(ent);
		free(qual_path);
		return (NULL);
	}
	free(qual_path);
	ent->name = child;
	return (ent);
}
