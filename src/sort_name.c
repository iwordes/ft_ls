/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:23:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/16 09:32:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Sort by ASCII name.
*/

char	utf8_len_(uint32_t codept)
{
	if (codept < 0x80)
		return (1);
	else if (codept < 0x800)
		return (2);
	else if (codept < 0x10000)
		return (3);
	else
		return (4);
}

#define U8DEC(N) ft_utf8_decode(N)

long	sort_name(t_ent *ent1, t_ent *ent2)
{
	uint8_t		*name1;
	uint8_t		*name2;
	uint32_t	c1;
	uint32_t	c2;

	name1 = (uint8_t*)ent1->name;
	name2 = (uint8_t*)ent2->name;
	while (1)
	{
		c1 = U8DEC(name1);
		c2 = U8DEC(name2);
		if (c1 == 0 || c1 != c2 || c1 == ~0U || c2 == ~0U)
			break ;
		name1 += utf8_len_(c1);
		name2 += utf8_len_(c2);
	}
	return ((long)c2 - (long)c1);
}
