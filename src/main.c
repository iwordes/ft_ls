/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:53:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/11 12:19:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		g_exit = 0;

int		main(int argc, char **argv)
{
	t_ls			config;
	int				tgt_cnt;
	char			**targets;

	ls_init_config(&config);
	ls_parse_args(argc, argv, &config);
	ls_parse_targets(argc, argv, &tgt_cnt, &targets);
	ls_targets_sort(targets, tgt_cnt);
	debug_init(targets, tgt_cnt, &config);
	if (tgt_cnt == 0)
		ls_list(".", &config);
	else
	{
		if (tgt_cnt > 1)
			config.multiple_targets = TRUE;
		ls_list_targets(targets, tgt_cnt, &config);
	}
	return (g_exit);
}
