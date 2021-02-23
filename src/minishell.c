#include "./include/minishell.h"

void    prompt()
{
    ft_putstr_fd("\033[0;32m$>\033[0m", 2);
}

void    minishell_loop()
{
    char *tmp;
    int r;

    tmp = NULL;
    r = 0;
    while (1)
    {
        if (!g_sh.c)
        {
            g_sh.line = NULL;
            tmp = NULL;
            prompt();
            while ((r = readline()) <= 0)
                tmp = ft_strjoin(tmp, g_sh.line);
            g_sh.line = ft_strjoin(tmp, g_sh.line);
        }
        ft_putendl_fd(g_sh.line, 2);
        if (!ft_strcmp(g_sh.line, "exit"))
            exit(0);
        free(g_sh.line);
        if (g_sh.c)
            exit(g_sh.status);
    }
}

void    init_errors()
{
    g_sh.errors[1] = ft_strdup("minishell: syntax error near unexpected token `|'");
    g_sh.errors[2] = ft_strdup("minishell: syntax error near unexpected token `;'");
    g_sh.errors[3] = ft_strdup("minishell: syntax error near unexpected token `||'");
    g_sh.errors[4] = ft_strdup("minishell: syntax error near unexpected token `;;'");
    g_sh.errors[5] = ft_strdup("minishell: syntax error near unexpected token `|;'");
    g_sh.errors[6] = ft_strdup("minishell: syntax error near unexpected token `;|'");
    g_sh.errors[7] = ft_strdup("minishell: syntax error near unexpected token `<<'");
    g_sh.errors[8] = ft_strdup("minishell: syntax error near unexpected token `>'");
    g_sh.errors[9] = ft_strdup("minishell: syntax error near unexpected token `newline'");
    g_sh.errors[10] = ft_strdup("minishell: syntax error multiline");
}

void    init_pwd()
{
    char *pwd;

    if (!(pwd = ft_getenv("PWD")))
    {
        if (!(pwd = getcwd(NULL, 0)))
            pwd = ft_strdup("");
        ft_setenv("PWD", pwd);
    }
    free(pwd);
}