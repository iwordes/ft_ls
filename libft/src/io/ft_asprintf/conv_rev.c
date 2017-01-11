/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:29:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/02 18:42:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Reverse the input string.
*/

ssize_t	ft_asprintf_conv_rev(char **string, va_list arg, t_printer *p)
{
	char	*raw;
	ssize_t	length;

	if (p->length & 4 == 4)
		return (ft_asprintf_conv_rev_long(string, arg, p));
	length = ft_asprintf_conv_str(&raw, arg, p);
	if (raw == NULL)
		return (-1);
	ft_strrev(raw);
	*string = raw;
	return (length);
}
