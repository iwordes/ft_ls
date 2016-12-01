NAME    = ft_ls
AUTHOR  = iwordes
VERSION = 1.0.0

CC      = gcc
CF      = -Wall -Wextra -Werror -I include -L lib -l ft -l fs

SRC     = main.c
SRC    := $(addprefix src/,$(SRC))

.PHONY: all
all: bin/$(NAME)

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -rf bin/$(NAME)

.PHONY: re
re: fclean all


bin/$(NAME): lib/libft.a lib/libfs.a $(SRC)
	$(CC) $(CF) -o $@ $(SRC)
