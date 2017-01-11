/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 18:36:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ent			*ls_create_ent(const char *path, char *child)
{
	char	*qual_path;
	t_ent	*ent;

	LS_MGUARD(ent = (t_ent*)malloc(sizeof(t_ent)));
	LS_MGUARD(qual_path = fs_join(path, child));
	if (lstat(qual_path, &ent->info) != 0)
	{
		free(ent);
		free(qual_path);
		return (NULL);
	}
	ent->name = child;
	if (LS_ISLNK(ent))
	{
		LS_MGUARD(ent->link = ft_strdup(fs_readlink(qual_path)));
		ent->dirlink = fs_isdir(qual_path);
	}
	else
	{
		ent->link = NULL;
		ent->dirlink = FALSE;
	}
	ent->has_xattr = (listxattr(qual_path, NULL, 0, XATTR_NOFOLLOW) > 0);
	free(qual_path);
	return (ent);
}
