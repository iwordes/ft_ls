/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_targets_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:21:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/09 11:30:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Sort the given targets by name, ascending.
*/

void	ls_targets_sort(char **target, int l)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((i += 1) < l)
	{
		if (ft_strcmp(target[i - 1], target[i]) > 0)
		{
			tmp = target[i--];
			target[i + 1] = target[i];
			while (i > 0 && ft_strcmp(target[i], tmp) > 0)
			{
				target[i] = target[i - 1];
				i -= 1;
			}
			target[i] = tmp;
		}
	}
}
