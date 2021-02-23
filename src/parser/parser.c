#include "../include/minishell.h"

int    readline()
{   
	int r;
	// printf("|%s\n", g_sh.line);
    r = get_next_line(0, &g_sh.line);
	// printf("|%s| %d\n", g_sh.line, r);
	if ((r == -2 && !g_sh.line))
	{
		ft_putendl_fd("\nexit", 2);
		exit(g_sh.status);
	}
	return r;
}