/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_targets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 13:14:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ls_list_target_files()
{
	
}

/*
** Iterate over each target, formatting a table from the files and printing it,
** then iterating over each directory and listing its contents.
**
** If conf->recurse is enabled, print all subdirectories, too.
*/

void	ls_list_targets(t_ent *target, t_ls *config)
{
	int		t;
	char	*files;
	char	*dirs;

	t = 0;
	files = NULL;
	while (target[t]->parent != NULL)
	{
		if (target[t]->)

		files = ft_drealloc(files, t, t + 1);
		files[t] =
		t += 1;
	}
	t = 0;
	dirs = NULL;
	while (target[t]->parent != NULL)
	{

		t += 1;
	}
}
