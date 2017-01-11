/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:36:30 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/02 18:48:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Use the given precision as the base for numeric conversion.
*/

ssize_t	ft_asprintf_conv_base(char **string, va_list arg, t_printer *p)
{
	char		base;

	if ((base = p->prec) < 2 || base > 64)
		base = 10;
	p->alt = FALSE;
	p->prec = -1;
	*string = ft_asprintf_uitoa_base(ft_printf_cast_unsigned(arg, p), base, p);
	if (*string == NULL)
		return (-1);
	return (ft_strlen(*string));
}
