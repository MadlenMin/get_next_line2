/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mminasya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:48:59 by mminasya          #+#    #+#             */
/*   Updated: 2025/04/04 20:43:00 by mminasya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*myfree(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

char	*fill_stash(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (stash && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (myfree(stash));
		free(stash);
		stash = tmp;
	}
	if (bytes_read < 0)
		return (myfree(stash));
	return (stash);
}

char	*the_line(char *stash)
{
	char	*newline_pos;

	if (!stash || !*stash)
		return (NULL);
	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		return (ft_substr(stash, 0, (newline_pos - stash) + 1));
	return (ft_substr(stash, 0, ft_strlen(stash)));
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*newline_pos;

	newline_pos = ft_strchr(stash, '\n');
	if (!newline_pos)
		return (myfree(stash));
	new_stash = ft_strdup(newline_pos + 1);
	if (!new_stash)
		return(myfree(stash));
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = the_line(stash);
	stash = update_stash(stash);
	return (line);
}
/*
int main()
{
        int fd;
        fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));

        close(fd);
        return 0;
}*/
