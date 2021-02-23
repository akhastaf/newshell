#include "../include/minishell.h"

void    builtins_init()
{
    // g_sh.builtins_fun[0] = &builtins_pwd;
    // g_sh.builtins_fun[1] = &builtins_cd;
    // g_sh.builtins_fun[2] = &builtins_env;
    // g_sh.builtins_fun[3] = &builtins_echo;
    // g_sh.builtins_fun[4] = &builtins_unset;
    // g_sh.builtins_fun[5] = &builtins_export;
    // g_sh.builtins_fun[6] = &builtins_exit;
    g_sh.builtins_str[0] = ft_strdup("pwd");
    g_sh.builtins_str[1] = ft_strdup("cd");
    g_sh.builtins_str[2] = ft_strdup("env");
    g_sh.builtins_str[3] = ft_strdup("echo");
    g_sh.builtins_str[4] = ft_strdup("unset");
    g_sh.builtins_str[5] = ft_strdup("export");
    g_sh.builtins_str[6] = ft_strdup("exit");
}
