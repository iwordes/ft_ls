/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 13:59:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ent			*ls_create_ent(const char *path, char *child, t_ls *conf)
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
	ent->name = child;
	if (conf->detailed && S_ISLNK(ent->info.st_mode))
		ent->link_to = ft_strdup(fs_readlink(qual_path));
	else
		ent->link_to = NULL;
	ent->has_xattr = (listxattr(qual_path, NULL, 0, 0) > 0);
	free(qual_path);
	return (ent);
}
