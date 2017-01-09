/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_table_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:29:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 16:53:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	detailed_total_(t_ent **ent)
{
	uintmax_t	total;
	unsigned	i;

	i = ~0;
	total = 0;
	while (ent[(i += 1)] != NULL)
		total += ent[i]->info.st_blocks;
	ft_printf("total %ju\n", total);
}

void		ls_table_print(t_ent **ent, t_ls *conf)
{
	unsigned	i;
	t_lspad		pad;

	i = 0;
	if (!conf->detailed)
		while (ent[i] != NULL)
			ft_printf("%s\n", ls_fmt_name(ent[i++], conf));
	else
	{
		if (ent[0] != NULL)
			detailed_total_(ent);
		ls__genpad(ent, &pad, conf);
		while (ent[i] != NULL)
			ls_ent_print_detailed(ent[i++], &pad, conf);
	}
}
