/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:34:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/03 18:15:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ls_parse_args(int argc, char **argv, t_ls *config)
{
	int		a;
	size_t	i;

	a = 1;

	// DEBUG
	printf("\e[1;96mSwitches:\e[0m -");

	while (a < argc && argv[a][0] == '-')
	{
		if (ft_strequ(argv[a], "--"))
			break ;
		i = 1;
		while (argv[a][i] != 0)
		{
			if (!ls_parse_switch(argv[a][i], config))
				err_illegal_opt(argv[0], argv[a][i]);
			i += 1;
		}
		a += 1;
	}

	// DEBUG
	printf("\n");

}
