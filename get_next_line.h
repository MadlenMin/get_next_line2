#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# endif 

# include <fcntl.h>

void myfree(char **line);
char *read_error(char **stash);
char *fill_stash(int fd, char *stash);
char *read_line(char *stash);
char *get_next_line(int fd);
size_t ft_strlen(char *s);
char *ft_strdup(char *s1);
char *ft_strchr(char *s, int c);
char *ft_substr(char *s, unsigned int start, size_t len);
char *ft_strjoin(char *s1, char *s2);
# endif

