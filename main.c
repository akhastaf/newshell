#include "src/include/minishell.h"


void sig_c(int signum)
{
    if (!g_sh.pid && signum == SIGINT)
    {
        write(1, "\n", 1);
        ft_putstr_fd("\033[0;32m$>\033[0m", 2);
    }
    else if (g_sh.pid &&  signum == SIGQUIT)
        kill(g_sh.pid, SIGQUIT);

}

void    init_sh()
{
    g_sh.home = ft_getenv("HOME");
    g_sh.pl = NULL;
    g_sh.pid = 0;
    g_sh.ret = 0;
    g_sh.in = dup(0);
    g_sh.out = dup(1);
}

int     main(int ac, char **av, char **envp)
{
    signal(SIGINT, sig_c);
    signal(SIGQUIT, sig_c);
    init_env(envp);
    init_errors();
    init_shlvl();
    init_pwd();
    builtins_init();
    init_sh();
    ft_envremove("OLDPWD");
    if (ac == 3 && !ft_strcmp(av[1], "-c"))
    {
        g_sh.line = ft_strdup(av[2]);
        g_sh.c = 1;
    }
    else
        g_sh.c = 0;
    minishell_loop();
    return g_sh.ret;
}



void    init_shlvl()
{
    long value;
    char *env;
    char *v;

    env = ft_getenv("SHLVL");
    value = ft_atoll(env ? env : "");
    if (value >= 2147483647)
        value = -1;
    if (value >= 200000)
    {
        ft_putstr_fd("minishell: warning: shell level (", 2);
        ft_putstr_fd(ft_itoa(value + 1), 2);
        ft_putendl_fd(") too high, resetting to 1", 2);
        value = 0;
    }
    else if (value < 0)
        value = -1;
    v = ft_itoa(value + 1);
    ft_envremove("SHLVL");
    ft_setenv("SHLVL", v);
    free(v);
    free(env);
}