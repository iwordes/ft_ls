/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_timeyear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:18:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/15 19:40:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define SEC_IN_6MO (86400 * (365 / 2))

static void	year_(char buffer[20], char *stamp)
{
	size_t	i;

	while (stamp[0] == ' ')
		stamp += 1;
	i = ~0;
	while (ft_isdigit(stamp[i += 1]))
		buffer[i] = stamp[i];
	buffer[i] = 0;
}

const char	*ls_fmt_timeyear(time_t epoch)
{
	static char	buffer[20];
	time_t		now;

	now = time(NULL);
	if (epoch > (now - SEC_IN_6MO) && epoch < (now + SEC_IN_6MO))
	{
		ft_strncpy(buffer, ctime(&epoch) + 11, 5);
		buffer[6] = 0;
	}
	else
	{
		buffer[0] = ' ';
		year_(buffer + 1, ctime(&epoch) + 20);
	}
	return (buffer);
}
