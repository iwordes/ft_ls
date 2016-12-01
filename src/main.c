#include <ft_ls.h>

int			main(int argc, char **argv)
{
	t_ls	args;

	if (argc == 1)
		ls_list(".", args);
	else
	{
		// TODO: Parse arguments.
		// TODO: List each non-argument's contents, or itself.
	}
}
