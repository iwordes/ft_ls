/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_targets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:56:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/06 18:59:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Create the available targets by offsetting the input arguments.
*/

void	ls_parse_targets(int argc, char **argv, int *tgt_cnt, char ***targets)
{
	int		i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != 0)
	{
		i += 1;
		if (argv[i - 1][1] == '-')
			break ;
	}
	*tgt_cnt = argc - i;
	*targets = argv + i;
}
