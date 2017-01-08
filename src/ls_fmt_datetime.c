/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_datetime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:02:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 09:13:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** timebuff[4:7]: Mon _D
** timebuff[7:12]: HH:MM
** timebuff[16:]: YYYY[Y...]
*/

static void	hhmm_(char *end, char *hhmm)
{
	int		i;

	i = 1;
	while ((i -= 1) > -5)
		end[i] = hhmm[i];
}

static void	year_(char *end, time_t year)
{
	while (end -= 1)
	{
		*end = '0' + (year % 10);
		if ((year /= 10) == 0)
			break ;
	}
}

#define SEC_IN_YEAR 31556926

/*
** At least one space is necessary between the first 6-byte MonDD chunk and
** either the HH:MM or year.
*/

const char	*ls_fmt_datetime(time_t epoch)
{
	static char	buffer[32];
	char		*timebuff;
	time_t		year;

	timebuff = ctime(&epoch) + 4;
	ft_strncpy(buffer, timebuff, 6);
	ft_strcpy(buffer + 6, "      ");
	if ((year = epoch / SEC_IN_YEAR) == (time(NULL) / SEC_IN_YEAR))
	{
		ft_strncpy(buffer + 6, timebuff + 6, 6);
		buffer[12] = 0;
	}
	else if (ft_intlen(year) > 4)
		ls__naitoa(buffer + 7, year);
	else
		year_(buffer + 12, year);
}
