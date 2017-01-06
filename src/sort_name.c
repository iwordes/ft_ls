/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:23:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 16:19:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Sort by ASCII name.
*/

int		sort_name(t_ent *ent1, t_ent *ent2)
{
	return (ft_strcmp(ent2->name, ent1->name));
}
