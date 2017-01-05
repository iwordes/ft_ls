/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:24:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/05 15:02:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO NOTE TODO: CHANGE THIS!!! TODO NOTE TODO NOTE NOTE TODO
#include                <stdio.h>




#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>

# include <libfs.h>
# include <libft.h>

# define ERR_FSTAT err_fstat(); return
# define ERR_OPENDIR err_opendir(); return

typedef enum	e_acm
{
	acc,
	chn,
	mod
}				t_acm;

typedef enum	e_order
{
	name = 0,
	accessed = 4,
	changed = 5,
	modified = 6
}				t_order;
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
	char			detailed;
	char			follow_sym;
	char			recurse;
	char			show_all;
	char			show_hidden;
	char			show_inode;
	char			sort_rev;

	t_order			order;
	t_acm			time;

	char			multiple_targets;
}					t_ls;

void				ls__naitoa(char buffer[20], uintmax_t integer);

const char			*ls_fmt_group(gid_t gid);
const char			*ls_fmt_inode(ino_t inode);
const char			*ls_fmt_mode(mode_t mode);
const char			*ls_fmt_size(off_t size);
const char			*ls_fmt_user(uid_t uid);

void				ls_init_config(t_ls *config);
t_ent				*ls_create_ent(const char *path, char *name);
void				ls_list(const char *path, t_ls *config);
t_ent				**ls_listdir(const char *path);
void				ls_parse_args(int argc, char **argv, t_ls *config);
char				ls_parse_switch(char sw, t_ls *config);
void				ls_parse_targets(int argc, char **argv, int *t, char ***tg);
void				ls_table_fmt(const char *parent, t_ent **o_ent, t_ls *conf);
void				ls_table_sort(t_ent **ent, t_order method, char reverse);
void				ls_table_print(t_ent **ent, t_ls *conf);

void				err_illegal_opt(const char *bin, char opt);

int					sort_accessed(t_ent *ent1, t_ent *ent2);
int					sort_changed(t_ent *ent1, t_ent *ent2);
int					sort_modified(t_ent *ent1, t_ent *ent2);
int					sort_name(t_ent *ent1, t_ent *ent2);

void				sw_show_all(t_ls *config);
void				sw_show_hidden(t_ls *config);
void				sw_long_format(t_ls *config);
void				sw_recursive(t_ls *config);
void				sw_sort_reverse(t_ls *config);
void				sw_sort_modified(t_ls *config);

extern char			*g_name;

#endif
