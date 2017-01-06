/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls__sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:09:46 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 13:10:05 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ls__sort(t_ent **ent, int (*cmp)(t_ent*, t_ent*), char reverse)
{
	int		diff;
	t_ent	*tmp;
	t_ent	**i;

	i = ent;
	while ((i += 1) && *(i - 1) != NULL && *i != NULL)
	{
		diff = cmp(*(i - 1), *i);
		if ((reverse) ? (diff > 0) : (diff < 0))
		{
			tmp = *i;
			while (i != ent && (diff = cmp(*(i - 1), tmp)) != 0
				&& ((reverse) ? (diff > 0) : (diff < 0)))
			{
				*i = *(i - 1);
				i -= 1;
			}
			*i = tmp;
		}
	}
}
