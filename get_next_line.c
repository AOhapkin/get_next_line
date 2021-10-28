#include "get_next_line.h"
#include "stdio.h"

char	*save_buffer(int fd, char *buff)
{
	char	*result;
	int		bytes;

	if (!buff)
		buff = malloc(sizeof(char));
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
		result = ft_strjoin(buff, result);
		if (ft_strchr(result, '\n'))
			break;
	}
	free(result);
	return (buff);
}

char	*get_next_line(int fd)
{
//	int 	i = 0;
	static char	*buff;
	char	*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buff = save_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = save_line(buff);
	buff = cut_buffer(buff);

//	while (i < BUFFER_SIZE) {
//		buff[i++] = 0;
//	}
//	ssize_t read_bytes = read(fd, buff, BUFFER_SIZE);
//	printf("Прочитано %li байт\nВот что прочитано: \"%s\"", read_bytes, buff);
	return line;
}