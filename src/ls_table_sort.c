/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:12:34 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 16:05:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		align_table__1(t_ent **ent)
{
	t_ent	*tmp;
	t_ent	**i;

	i = ent;
	while (!ft_strequ(ent[0]->name, ".") && ((i += 1) || TRUE))
	{
		if (ft_strequ((*i)->name, "."))
		{
			tmp = *i;
			while (i != ent)
			{
				*i = *(i - 1);
				i -= 1;
			}
			*i = tmp;
		}
	}
}

static void		align_table__2(t_ent **ent)
{
	t_ent	*tmp;
	t_ent	**i;

	i = ent + 1;
	while (!ft_strequ(ent[1]->name, "..") && ((i += 1) || TRUE))
	{
		if (ft_strequ((*i)->name, ".."))
		{
			tmp = *i;
			while (i != ent + 1)
			{
				*i = *(i - 1);
				i -= 1;
			}
			*i = tmp;
		}
	}
}

static void		sort(t_ent **ent, int (*cmp)(t_ent*, t_ent*), char reverse)
{
	int		diff;
	t_ent	*tmp;
	t_ent	**i;

	i = ent;
	while ((i += 1) && *(i - 1) != NULL && *i != NULL)
	{
		diff = cmp(*(i - 1), *i);
		if ((reverse) ? (diff < 0) : (diff > 0))
		{
			tmp = *i;
			while (i != ent && (diff = cmp(*(i - 1), tmp)) != 0
				&& ((reverse) ? (diff < 0) : (diff > 0)))
			{
				*i = *(i - 1);
				i -= 1;
			}
			*i = tmp;
		}
	}
}

static int		(*g_sort[])(t_ent*, t_ent*) =
{
	sort_name,
	sort_size,
	sort_accessed,
	sort_created,
	sort_modified
};

/*
** Sort a NULL-terminated array of t_ent* by the method specified.
*/

void			ls_table_sort(t_ent **ent, t_order method, char reverse)
{
	align_table__1(ent);
	align_table__2(ent);
	sort(ent + 2, g_sort[method], reverse);
}
