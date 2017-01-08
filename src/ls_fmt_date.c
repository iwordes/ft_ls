/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:15:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 09:35:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_date(time_t epoch)
{
	static char	buffer[7];

	ft_strncpy(buffer, ctime(&epoch) + 4, 6);
	return (buffer);
}
