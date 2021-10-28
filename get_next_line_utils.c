#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		dest_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * dest_len);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
