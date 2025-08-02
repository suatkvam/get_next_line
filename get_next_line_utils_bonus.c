#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > 9223372036854775807 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(const char *stash, const char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!stash)
		stash = ft_strdup("");
	if (!stash || !buffer)
		return (NULL);
	new_str = ft_calloc(1, (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!new_str)
		return (NULL);
	len = ft_strlen(stash);
	while (i < len)
	{
		new_str[i] = stash[i];
		i++;
	}
	while (j < ft_strlen(buffer))
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free((void *)stash);
	return (new_str);
}
