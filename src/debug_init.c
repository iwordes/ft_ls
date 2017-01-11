/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:28:38 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/11 10:53:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#ifdef DEBUG

# define MSG_ON "\e[92menabled\e[0m"
# define MSG_OFF "\e[91mdisabled\e[0m"

void	debug_init(char **targets, int t, t_ls *config)
{
	int		i;

	ft_printf("\e[1;35m-- DEBUG --\e[0m\n");
	ft_printf("\e[1;96mTargets:\e[0m\n");
	i = ~0;
	while ((i += 1) < t)
		ft_printf("\e[93m%s\e[0m\n", targets[i]);
	(i == 0) && ft_printf("\e[1;91mNone\e[0m\n");
	ft_printf("\n\e[1;96mConfig:\e[0m\n");
	ft_printf("Color:       %s\n", (config->colorize) ? MSG_ON : MSG_OFF);
	ft_printf("Long Format: %s\n", (config->detailed) ? MSG_ON : MSG_OFF);
	ft_printf("Recursion:   %s\n", (config->recurse) ? MSG_ON : MSG_OFF);
	ft_printf("Show All:    %s\n", (config->show_all) ? MSG_ON : MSG_OFF);
	ft_printf("Show Hidden: %s\n", (config->show_hidden) ? MSG_ON : MSG_OFF);
	ft_printf("Sort Asc.:   %s\n", (config->sort_rev) ? MSG_ON : MSG_OFF);
	ft_printf("Sorting By:  \e[1;93m");
	(config->order == sort_accessed) && ft_printf("time accessed\e[0m\n");
	(config->order == sort_changed) && ft_printf("time changed\e[0m\n");
	(config->order == sort_created) && ft_printf("time created\e[0m\n");
	(config->order == sort_modified) && ft_printf("time modified\e[0m\n");
	(config->order == sort_name) && ft_printf("name\e[0m\n");
	ft_printf("\n");
}

#else

void	debug_init(char **targets, int t, t_ls *config)
{
	(void)targets;
	(void)t;
	(void)config;
}

#endif
