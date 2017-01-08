/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:24:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/08 15:29:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO NOTE TODO: CHANGE THIS!!! TODO NOTE TODO NOTE NOTE TODO
#include                <stdio.h>




#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <sys/xattr.h>

# include <libfs.h>
# include <libft.h>

# define LS_MALLOC_GUARD(MEM) if ((MEM) == NULL) exit(ENOMEM)
# define LS_MGUARD(MEM) LS_MALLOC_GUARD(MEM)

typedef enum		e_time
{
	time_modified,
	time_accessed,
	time_changed,
	time_created
}					t_time;

typedef struct		s_lspad
{
	unsigned		inode;
	unsigned		mode;
	unsigned		nlinks;
	unsigned		user;
	unsigned		group;
	unsigned		size;
	unsigned		timeyear;
}					t_lspad;

typedef struct		s_ent
{
	char			*name;
	char			*link_to;
	struct stat		info;
	char			has_xattr;
}					t_ent;

typedef struct		s_ls
{
	char			colorize;
	char			detailed;
	char			do_sort;
	char			follow_sym;
	char			one_column;
	char			recurse;
	char			show_all;
	char			show_hidden;
	char			show_inode;
	char			sort_rev;

	long			(*order)(t_ent*, t_ent*);
	long			(*order_cache)(t_ent*, t_ent*);
	t_time			time;

	char			multiple_targets;
}					t_ls;

time_t				ls__propertime(t_ent *ent, t_ls *conf);
void				ls__naitoa(char buffer[20], uintmax_t integer);
void				ls__sort(t_ent **e, int (*cmp)(t_ent*, t_ent*), char rev);

void				ls_ent_print_detailed(t_ent *ent, t_lspad *pad, t_ls *conf);

const char			*ls_fmt_group(gid_t gid);
const char			*ls_fmt_inode(ino_t inode);
const char			*ls_fmt_nlinks(nlink_t nlinks);
const char			*ls_fmt_mode(t_ent *ent);
const char			*ls_fmt_size(off_t size);
const char			*ls_fmt_user(uid_t uid);
const char			*ls_fmt_date(time_t epoch);
const char			*ls_fmt_timeyear(time_t epoch);
const char			*ls_fmt_name(t_ent *ent, t_ls *conf);

void				ls_init_config(t_ls *config);
t_ent				*ls_create_ent(const char *path, char *name, t_ls *conf);
char				ls_list(const char *path, t_ls *config);
t_ent				**ls_listdir(const char *path, t_ls *conf);
void				ls_list_targets(char **targets, unsigned t, t_ls *conf);
void				ls_parse_args(int argc, char **argv, t_ls *config);
char				ls_parse_switch(char sw, t_ls *config);
void				ls_parse_targets(int argc, char **argv, int *t, char ***tg);

void				ls_table_align(t_ent **table);
void				ls_table_fmt(const char *parent, t_ent **table, t_ls *conf);
void				ls_table_print(t_ent **table, t_ls *conf);
void				ls_table_sort(t_ent **t, long (*c)(t_ent*, t_ent*), char r);
void				ls_table_sort_adv(t_ent **t, long (*c1)(t_ent*, t_ent*),
										long (*c2)(t_ent*, t_ent*), char r);

void				err_illegal_opt(const char *bin, char opt);
char				err_list(const char *path);
char				err_path(const char *path);

long				sort_accessed(t_ent *ent1, t_ent *ent2);
long				sort_changed(t_ent *ent1, t_ent *ent2);
long				sort_created(t_ent *ent1, t_ent *ent2);
long				sort_modified(t_ent *ent1, t_ent *ent2);
long				sort_name(t_ent *ent1, t_ent *ent2);
long				sort_size(t_ent *ent1, t_ent *ent2);

void				sw_1_column(t_ls *cfg);
void				sw_colorize(t_ls *cfg);
void				sw_show_all(t_ls *cfg);
void				sw_show_hidden(t_ls *cfg);
void				sw_show_inode(t_ls *cfg);
void				sw_long_format(t_ls *cfg);
void				sw_recursive(t_ls *cfg);
void				sw_sort_accessed(t_ls *cfg);
void				sw_sort_changed(t_ls *cfg);
void				sw_sort_created(t_ls *cfg);
void				sw_sort_reverse(t_ls *cfg);
void				sw_sort_size(t_ls *cfg);
void				sw_sort_modified(t_ls *cfg);

extern char			*g_name;
extern int			g_exit;

#endif
