#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*extract_line(char *stash)
{
	char	*newline;
	size_t	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (newline)
		i = (newline - stash) + 1;
	else
		i = ft_strlen(stash);
	return (ft_substr(stash, 0, i));
}

char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*new_line;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (!new_line)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(new_line + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		read_byte;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
