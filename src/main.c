/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:53:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 19:20:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*g_name;
int		g_exit = 0;

int		main(int argc, char **argv)
{
	t_ls			config;
	int				tgt_cnt;
	char			**targets;

	g_name = argv[0];
	ls_init_config(&config);
	ls_parse_args(argc, argv, &config);
	ls_parse_targets(argc, argv, &tgt_cnt, &targets);

	/*
	ft_printf("sorter: ");
	if (config.order == sort_name)
		ft_printf("name\n");
	else if (config.order == sort_size)
		ft_printf("size\n");
	else if (config.order == sort_accessed)
		ft_printf("time accessed\n");
	else if (config.order == sort_changed)
		ft_printf("time changed\n");
	else if (config.order == sort_created)
		ft_printf("time created\n");
	else if (config.order == sort_modified)
		ft_printf("time modified\n");
	else
		ft_printf("wat\n");
*/

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
