NAME    = ft_ls
AUTHOR  = iwordes
VERSION = 1.0.0

CC      = gcc
CF      = -Wall -Wextra -Werror
CF     += -I include -I libfs/include -I libft/include
CF     += -L lib -l fs -l ft

SRC     = main.c
SRC    += err_illegal_opt.c \
		  err_list.c \
		  err_path.c
SRC    += ls__genpad.c \
		  ls__propertime.c \
		  ls__naitoa.c \
		  ls_create_ent.c \
		  ls_destroy_ent.c \
		  ls_destroy_table.c \
		  ls_ent_print_detailed.c \
		  ls_fmt_devmajor.c \
		  ls_fmt_devminor.c \
		  ls_fmt_group.c \
		  ls_fmt_inode.c \
		  ls_fmt_mode.c \
		  ls_fmt_nlinks.c \
		  ls_fmt_size.c \
		  ls_fmt_user.c \
		  ls_fmt_date.c \
		  ls_fmt_timeyear.c \
		  ls_fmt_name.c \
		  ls_init_config.c \
		  ls_list.c \
		  ls_listdir.c \
		  ls_list_targets.c \
		  ls_parse_args.c \
		  ls_parse_switch.c \
		  ls_parse_targets.c \
		  ls_table_align.c \
		  ls_table_fmt.c \
		  ls_table_print.c \
		  ls_table_sort.c \
		  ls_table_sort_adv.c \
		  ls_targets_sort.c
SRC    += sort_accessed.c \
		  sort_changed.c \
		  sort_created.c \
		  sort_modified.c \
		  sort_name.c \
		  sort_size.c
SRC    += sw_1_column.c \
		  sw_colorize.c \
		  sw_show_all.c \
		  sw_show_hidden.c \
		  sw_show_inode.c \
		  sw_long_format.c \
		  sw_recursive.c \
		  sw_sort_accessed.c \
		  sw_sort_changed.c \
		  sw_sort_created.c \
		  sw_sort_reverse.c \
		  sw_sort_size.c \
		  sw_sort_modified.c
SRC    := $(addprefix src/,$(SRC))

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo No object files removed from ./build!
	make clean -C libfs
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f lib/libfs.a
	rm -f lib/libft.a
	rm -f libfs/libfs.a
	rm -f libft/libft.a

.PHONY: re
re: fclean all

$(NAME): lib/libfs.a lib/libft.a $(SRC)
	@mkdir -p $(@D)
	$(CC) $(CF) -o $@ $(SRC)

lib/libfs.a:
	make -C libfs
	cp -f libfs/libfs.a lib/

lib/libft.a:
	make -C libft
	cp -f libft/libft.a lib/
