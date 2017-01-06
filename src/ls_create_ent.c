/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 09:22:18 by iwordes          ###   ########.fr       */
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
	if (S_ISLNK(ent->info.st_mode) && fs_readlink(qual_path) != NULL)
	{
		ent->name = FT_VSTRJOIN(child, " -> ", fs_readlink(qual_path));
		free(child);
	}
	else
		ent->name = child;
	ent->has_xattr = (listxattr(qual_path, NULL, 0, 0) > 0);
	free(qual_path);
	return (ent);
}
