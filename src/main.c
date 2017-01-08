/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:53:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/07 16:40:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*g_name;

int		main(int argc, char **argv)
{
	t_ls			config;
	int				tgt_cnt;
	char			**targets;

	g_name = argv[0];
	ls_init_config(&config);
	ls_parse_args(argc, argv, &config);
	ls_parse_targets(argc, argv, &tgt_cnt, &targets);
	if (tgt_cnt == 0)
		ls_list(".", &config);
	else
	{
		if (tgt_cnt > 1)
			config.multiple_targets = TRUE;
		ls_list_targets(targets, tgt_cnt, &config);
	}
	return (0);
}
