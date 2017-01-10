/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_destroy_ent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:43:08 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/10 13:53:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ls_destroy_ent(t_ent *ent)
{
	free(ent->name);
	free(ent->raw_link);
	free(ent->qual_link);
	free(ent);
}
