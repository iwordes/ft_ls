/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls__naitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:33:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:38:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Non-Allocating Integer to ASCII
*/

void	ls__naitoa(char buff[20], uintmax_t num)
{
	int		i;

	i = ft_uintlen(num);
	buff[i] = 0;
	while (TRUE)
	{
		buff[(i -= 1)] = '0' + (num % 10);
		if ((num /= 10) == 0)
			break ;
	}
}
