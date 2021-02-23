#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include "strcuts.h"
# define ULIMIT 1

t_sh    g_sh;

void    init_shlvl();
void    init_errors();
void    builtins_init();
void    init_pwd();
void    init_sh();

void    minishell_loop();

int    init_env(char **env);
int    ft_envremove(char *var);
int    ft_setenv(char *var, char *val);
int    ft_envadd(char *var);
char    *ft_getenv(char *var);

int    readline();
char	*ft_checkerror(int fd, char **buff);
int		ft_readline(int fd, char **str);
int		get_next_line(int fd, char **line);

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strjoin(char  *s1, char  *s2);
int		ft_strcmp(const char *s1, const char *s2);
char			*ft_itoa(int n);
long long		ft_atoll(const char *str);
int     ft_size_arg(char **arg);
size_t  ft_strlen(char const *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif