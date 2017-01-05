/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_inode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:29:44 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 14:37:38 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_inode(ino_t inode)
{
	static char	buffer[20];

	ls__naitoa(buffer, inode);
	return (buffer);
}
