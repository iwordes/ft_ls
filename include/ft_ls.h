/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:24:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/04 14:34:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO NOTE TODO: CHANGE THIS!!! TODO NOTE TODO NOTE NOTE TODO
#include                <stdio.h>




#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>

# include <libfs.h>
# include <libft.h>

# define LS_SIZEMAP "KMGTPEZY"

# define ERR_FSTAT err_fstat(); return
# define ERR_OPENDIR err_opendir(); return

typedef enum	e_acm
{
	acc,
	crt,
	mod
}				t_acm;
/*
typedef struct		s_lstab
{

}					t_lstab;
*/
/*
** ent->child is a NULL-terminated array of pointers.
** An entry which is not a directory will be signaled by ent->child == NULL.
*/

typedef struct		s_ent
{
	char			*name;
	struct stat		info;
}					t_ent;

typedef struct		s_ls
{
	char			show_dot;
	char			show_hidden;
	char			detailed;
	char			hr_size;
	char			recurse;
	char			sort_acc;
	char			sort_crt;
	char			sort_rev;
	char			sort_mod;
	char			follow_sym;

	t_acm			order;
	t_acm			time;

	/*
	**
	*/

	char			multiple_targets;
}					t_ls;

void				ls_init_config(t_ls *config);
t_ent				*ls_create_ent(const char *path, char *name);
void				ls_list(const char *path, t_ls *config);
t_ent				**ls_listdir(const char *path);
void				ls_parse_args(int argc, char **argv, t_ls *config);
char				ls_parse_switch(char sw, t_ls *config);
void				ls_parse_targets(int argc, char **argv, int *t, char ***tg);

void				err_illegal_opt(const char *bin, char opt);

void				sw_show_hidden(t_ls *config);
void				sw_show_dot(t_ls *config);
void				sw_long_format(t_ls *config);
void				sw_recursive(t_ls *config);
void				sw_sort_reverse(t_ls *config);
void				sw_sort_modified(t_ls *config);

extern char			*g_name;

#endif
