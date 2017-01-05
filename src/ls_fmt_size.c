/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:26:29 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:59:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_size(off_t size)
{
	static char	buffer[20];

	ls__naitoa(buffer, size);
	return (buffer);
}
