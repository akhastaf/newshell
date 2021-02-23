#include "./include/minishell.h"

int    init_env(char **env)
{
    int l;
    int i;
    
    l = ft_size_arg(env);
    if (!(g_sh.env = malloc((l + 1) * sizeof(char*))))
        return 0;
    i = 0;
    while (env[i])
    {
        g_sh.env[i] = ft_strdup(env[i]);
        i++;
    }
    g_sh.env[i] = NULL;
    return 1;
}

char    *ft_getenv(char *var)
{
    int i;
    int j;

    i = 0;
    while (g_sh.env[i])
    {
        j = 0;
        while (var[j])
        {
            if (g_sh.env[i][j] == 0 || var[j] != g_sh.env[i][j])
                break;
            j++;
        }
        if (g_sh.env[i][j] == '=' && ft_strlen(var) == j)
                return ft_strdup(g_sh.env[i] + j + 1);
        
        i++;
    }
    return (NULL);
}

int    ft_envadd(char *var)
{
    int l;
    int i;
    char **env;
    
    l = ft_size_arg(g_sh.env);
    if (!(env = malloc((l + 2 ) * sizeof(char*))))
        return 0;
    ft_memcpy(env, g_sh.env, sizeof(char*) * l);
    env[l] = ft_strdup(var);
    env[l + 1] = NULL;
    g_sh.env = env;
    l = ft_size_arg(g_sh.env);
    return 1;
}

int    ft_setenv(char *var, char *val)
{
    int i;
    int j;
    char *new;

    if (!(new = malloc(sizeof(char) * (int)ft_strlen(val) + (int)ft_strlen(var) + 2)))
        return 0;
    i = 0;
    while (var[i])
    {
        new[i] = var[i];
        i++;
    }
    new[i] = '=';
    i++;
    j = 0;
    while (val[j])
    {
        new[i] = val[j];
        i++;
        j++;
    }
    new[i] = 0;
    i = 0;
    while (g_sh.env[i])
    {
        j = 0;
        while (var[j])
        {
            if (g_sh.env[i][j] == 0 || var[j] != g_sh.env[i][j])
                break;
            j++;
        }
        if (j == ft_strlen(var))
        {
            g_sh.env[i] = new;
            return 1;
        }
        i++;
    }
    if (j != ft_strlen(var))
        ft_envadd(new);
    free(new);
    return 0;
}

int    ft_envremove(char *var)
{
    int i;
    int j;
    int l;

    i = 0;
    l = ft_strlen(var);
    while (g_sh.env[i])
    {
        if (!ft_strncmp(g_sh.env[i], var, l) && g_sh.env[i][l] == '=')
        {
            j = 0;
            free(g_sh.env[i]);
            while (g_sh.env[i + j])
            {
                g_sh.env[i + j] = g_sh.env[i + j + 1];
                j++;
            }
            return 1;
        }
        i++;
    }
    return 0;
}