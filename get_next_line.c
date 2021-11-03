#include "get_next_line.h"
#include "stdio.h"

char	*read_until_divider(int fd)
{
	char	*buffer;
	char	*result;
	int		byte_read;
	char 	*tmp_for_freeing;

	result = NULL;
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFF_SIZE);
		if (byte_read == -1 || byte_read == 0)
			break;
		buffer[byte_read] = '\0';
		tmp_for_freeing = result;
		if (result)
			result = ft_strjoin(result, buffer);
		else
			result = ft_strdup(buffer);
		if (tmp_for_freeing) {
			free(tmp_for_freeing);
			tmp_for_freeing = NULL;
		}
		if (ft_strchr(buffer, DIVIDER))
			break;
	}
	free(buffer);
	return (result);
}

char	*cut_head_from_static(char **line_tail)
{
	char	*pointer_to_divider;
	char	*result;

	if (!line_tail)
		return (NULL);
	result = NULL;
	pointer_to_divider = ft_strchr(*line_tail, DIVIDER);
	if (pointer_to_divider == NULL || pointer_to_divider[0] == '\0' || pointer_to_divider[1] == '\0')
	{
		result = *line_tail;
		*line_tail = NULL;
	}
	else
	{
		result = *line_tail;
		*line_tail = ft_strdup(pointer_to_divider + 1);
		pointer_to_divider[1] = '\0';
	}
	return (result);
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
	static char	*line_tail;
	char		*read_to_divider;
	char		*tmp_for_freeing;
	char		*pointer_to_divider;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	else
	{
		char *new_head = cut_head_from_static(&line_tail);
		if (new_head && ft_strchr(new_head, DIVIDER))
		{
			return new_head;
		}
		else
		{
			read_to_divider = read_until_divider(fd);

			if (new_head && read_to_divider)
			{
				tmp_for_freeing = read_to_divider;
				read_to_divider = ft_strjoin(new_head, read_to_divider);
				free(tmp_for_freeing);
				free(new_head);
			}
			else if (new_head)
				read_to_divider = new_head;
			else if (!read_to_divider)
				return NULL;
			pointer_to_divider = ft_strchr(read_to_divider, DIVIDER);
			if (pointer_to_divider && pointer_to_divider[0] != '\0' &&
				pointer_to_divider[1] != '\0')
			{
				line_tail = ft_strdup(pointer_to_divider + 1);
				pointer_to_divider[1] = '\0';
				return read_to_divider;
			}
			else
				return read_to_divider;
		}
	}
}