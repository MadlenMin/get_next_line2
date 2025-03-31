#include "get_next_line.h"

size_t ft_strlen(char *s)
{
	size_t i;
	i = 0;
	if(!s)
		return(0);
	while(s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *s1)
{
	char *buffer;
	int i;
	int buffer_len;
	
	i = 0;
	buffer_len= ft_strlen(s1);
	buffer = (char *)malloc(buffer_len + 1);
	if(!buffer)
		return(NULL);
	while(s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return(buffer);
}

char *ft_strchr(char *s, int c )
{
	if(!s)
		return (NULL);
	while(*s)
	{
		if(*s == (char)c)
			return((char *)s);
		s++;
	}
	if(*s == (char)c)
		return ((char *)s);
	return(NULL);
}
char *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t i;
	size_t str_len;
	char *buffer;

	i = 0;
	if(!s)
		return(NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return(ft_strdup(""));
	if ( len > str_len - start)
		len =  str_len - start;
	buffer = (char *)malloc(len + 1);
	if(!buffer)
		return(NULL);
	while(i < len)
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
char *ft_strjoin(char *s1, char *s2)
{
	size_t i;
	size_t j;
	int	len;
	char	*new;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1);
	if(!new)
		return(NULL);
	i = 0;
	j = 0;
	while(s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

