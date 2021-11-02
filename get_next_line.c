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

char	*read_until_divider(int fd)
{
	char	*buffer;
	char	*result;
	int		byte_read;
	char 	*temp;

	result = NULL;
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buffer, BUFF_SIZE);
		if (byte_read == -1 || byte_read == 0)
			break;
		buffer[byte_read] = '\0';
		temp = result;
		if (result)
			result = ft_strjoin(result, buffer);
		else
			result = ft_strdup(buffer);
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
		if (ft_strchr(buffer, DIVIDER))
			break;
	}
	free(buffer);
	return (result);
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