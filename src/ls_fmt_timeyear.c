/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_timeyear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:18:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 13:10:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define SEC_IN_YEAR 31556926
#define SEC_IN_6MO (SEC_IN_YEAR / 2)

const char	*ls_fmt_timeyear(time_t epoch)
{
	static char	buffer[20];
	time_t		now;

	now = time(NULL);
	if (epoch > now || now - epoch > SEC_IN_6MO)
	{
		buffer[0] = ' ';
		ls__naitoa(buffer + 1, (epoch / SEC_IN_YEAR) + 1970);
	}
	else
	{
		ft_strncpy(buffer, ctime(&epoch) + 11, 5);
		buffer[6] = 0;
	}
	return (buffer);
}
