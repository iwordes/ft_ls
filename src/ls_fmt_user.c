/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fmt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:04:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 15:02:06 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

const char	*ls_fmt_user(uid_t uid)
{
	static char		buffer[20];
	struct passwd	*pwd;

	if ((pwd = getpwuid(uid)) != NULL)
		return (pwd->pw_name);
	ls__naitoa(buffer, uid);
	return (buffer);
}
