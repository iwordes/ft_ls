NAME    = ft_ls
AUTHOR  = iwordes
VERSION = 1.0.0

CC      = gcc
CF      = -Wall -Wextra -Werror
CF     += -I include -I libfs/include -I libft/include
CF     += -L lib -l fs -l ft

SRC     = main.c \
          err_illegal_opt.c \
          ls_create_ent.c \
          ls_init_config.c \
          ls_list.c ls_listdir.c \
          ls_parse_args.c ls_parse_switch.c ls_parse_targets.c \
		  ls_table_fmt.c ls_table_print.c ls_table_sort.c \
          sw_show_hidden.c sw_show_dot.c \
          sw_long_format.c \
          sw_recursive.c sw_sort_reverse.c \
          sw_sort_modified.c
SRC    := $(addprefix src/,$(SRC))

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -rf bin

.PHONY: re
re: fclean all

.PHONY: $(NAME)
$(NAME): bin/$(NAME)

bin/$(NAME): lib/libft.a $(SRC)
	@mkdir -p $(@D)
	$(CC) $(CF) -o $@ $(SRC)

lib/libft.a:
	make -C libft
	cp -f libft/libft.a lib/
