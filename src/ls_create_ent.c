/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_ent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:34:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 09:33:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ent			*ls_create_ent(const char *path, char *child, t_ls *conf)
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
	ent->link_to = NULL;
	if (conf->detailed && S_ISLNK(ent->info.st_mode))
		LS_MGUARD(ent->link_to = ft_strdup(fs_readlink(qual_path)));
	ent->has_xattr = (listxattr(qual_path, NULL, 0, 0) > 0);
	free(qual_path);
	return (ent);
}
