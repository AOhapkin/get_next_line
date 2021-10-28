#include "get_next_line.h"
#include "stdio.h"

char	*cut_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	temp = ft_newstr(ft_strlen(buffer) - i);
	j = 0;
	while (buffer[i])
	{
		temp[j] = buffer[i + j];
		j++;
	}
	free(buffer);
	return (temp);
}

char	*save_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] != '\n')
		i++;
	line = ft_newstr(i);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\n')
		line[i] = '\n';
	return (line);
}

char	*save_buffer(int fd, char *buffer)
{
	char	*result;
	int		bytes;
	char 	*temp;

	if (!buffer)
		buffer = malloc(sizeof(char));
	result = malloc(sizeof(char) * (BUFF_SIZE + 1));
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, result, BUFF_SIZE);
		if (bytes == -1)
		{
			free(result);
			return (NULL);
		}
		result[bytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, result);
		free(temp);
		if (ft_strchr(result, '\n'))
			break;
	}
	free(result);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char	*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buff = save_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = save_line(buff);
//	buff = cut_buffer(buff);


	printf("Вот что прочитано: \"%s\"", line);
	return line;
}