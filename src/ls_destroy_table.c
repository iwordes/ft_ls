/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_destroy_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:21:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 10:22:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ls_destroy_table(t_ent **table)
{
	unsigned	i;

	i = ~0;
	while (table[i += 1] != NULL)
		ls_destroy_ent(table[i]);
	free(table);
}
