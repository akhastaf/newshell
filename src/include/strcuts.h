#ifndef STRUCTS_H
# define STRUCTS_H

#include <sys/wait.h>

# define BUFFER_SIZE 1

# define BUILTINS_NUM 7

# define IS_SCARACTER(x) (x == '$' || x == ';' x == '|')


typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
    struct s_list   *prev;
}					t_list;

typedef int fun_ptr(char **);

typedef struct s_red
{
    char *type;
    char *file;
    // struct s_red *next;
}   t_red;


typedef struct  s_cmd
{
    char    *path;
    char    **arg;
    char    opr;
    int     pipe[2];
    int     fdin;
    int     fdout;
    t_list   *red;
    // struct s_cmd   *next;
    // struct s_cmd   *prev;
}           t_cmd;

typedef struct s_sh
{
    // t_cmd   *cmdlist;
    t_list     *pl;
    pid_t   pid;
    int     sigint;
    char    **env;
    fun_ptr *builtins_fun[BUILTINS_NUM];
    char    *builtins_str[BUILTINS_NUM];
    char    *line;
    int     status;
    int     in;
    int     out;
    int     is_b;
    long long     ret;
    int     error;
    char    *errors[11];
    char    *home;
    int     c;
}       t_sh;

#endif