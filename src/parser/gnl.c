#include "../include/minishell.h"
#include <fcntl.h>

char	*ft_checkerror(int fd, char **buff)
{
	if (!(BUFFER_SIZE >= 1) || (read(fd, *buff, 0) < 0))
		return (NULL);
	return (*buff);
}

int		ft_readline(int fd, char **str)
{
	char	*tmp;
	char	*buff;
	int		n;

	if ((!(buff = malloc(BUFFER_SIZE + 1))) || (!ft_checkerror(fd, &buff)))
	{
		free(buff);
		return (-1);
	}
	while ((n = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	if (buff[0] == 0)
		return -2;
	free(buff);
	buff = NULL;
	return (n);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[ULIMIT];
	char		*tmp;
	char		*s;
	int			n;
	n = 0;
	if ((n = ft_readline(fd, &str[fd])) == -1 || !line)
		return (-1);
	if (n == -2 && !str[fd])
		return -2;
	if (str[fd] && (s = ft_strchr(str[fd], '\n')))
	{
		*line = ft_strndup(str[fd], s - str[fd]);
		tmp = str[fd];
		str[fd] = ft_strdup(s + 1);
		free(tmp);
		return (1);
	}
	if (!n && str[fd])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}