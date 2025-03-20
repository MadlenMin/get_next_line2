#include "get_next_line.h"

void myfree(char **line)
{
	if(line && *line)
	{
		free(*line);
		*line = NULL;
	}
}
char *read_error(char **stash)
{
	myfree(stash);
	return(NULL);
}	
char *fill_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char 	*tmp;
	if (!stash)
		stash = ft_strdup("");
	if(!stash)
		return (NULL);
	while((bytes_read = read(fd, buffer, BUFFER_SIZE)> 0))
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if(!tmp)
			return (read_error(&stash));
		myfree(&stash);
		stash = tmp;

	}
	return((bytes_read < 0) ? read_error(&stash) : stash);
}
char *read_line(char *stash)
{
	char *line;
	size_t size;

	if(!stash || !*stash)
		return(NULL);
	size = ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n')) + 1;
	line = ft_substr(stash, 0 , size);
	if (!line)
	{
		myfree(&line);
		return (NULL);
	}
	return(line);
	
}
char *get_next_line(int fd)
{
	static char *stash;
	char *line;
	char *new_stash;
	char *newline_pos;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	stash = fill_stash(fd, stash);
	if(!stash)
		return(NULL);
	line = read_line(stash);
	if(!line)
		return(read_error(&stash));
	newline_pos = ft_strchr(stash, '\n');
	if(newline_pos)
		new_stash = ft_strdup(newline_pos + 1);
	else
		new_stash = NULL;
	myfree(&stash);
	stash = new_stash;
	return(line);
}
