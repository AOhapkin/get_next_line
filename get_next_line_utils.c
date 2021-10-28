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

char	*ft_newstr(size_t size)
{
	char	*dest;

	dest = malloc(size + 1);
	if (!dest)
		return (NULL);
	return ((char *)ft_memset(dest, 0, size));
}

void	*ft_memalloc(size_t size)
{
	void	*dest;

	dest = malloc(size);
	if (!dest)
		return (NULL);
	return (ft_memset(dest, 0, size));
}

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)dest;
	while (i < count)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
