/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:53:20 by gmyriah           #+#    #+#             */
/*   Updated: 2021/11/27 16:50:52 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

//void	free_tmp(char *tmp_for_freeing)
//{
//	free(tmp_for_freeing);
//	tmp_for_freeing = NULL;
//}

char	*set_result(char *result, char *buffer)
{
	if (result)
		result = ft_strjoin(result, buffer);
	else
		result = ft_strdup(buffer);
	return (result);
}

char	*read_until_divider(int fd, char *line)
{
	char	*buffer;
	int		byte_read;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !(ft_strchr(line, DIVIDER)))
	{
		byte_read = read(fd, buffer, BUFF_SIZE);
		if (byte_read <= 0)
			break ;
		buffer[byte_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

char	*get_head_from_line(char *line)
{
	char	*result;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != DIVIDER)
		i++;
	if (line[i] == DIVIDER)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != DIVIDER)
	{
		result[i] = line[i];
		i++;
	}
	if (line[i] == DIVIDER)
	{
		result[i] = DIVIDER;
		i++;
	}
	result[i] = '\0';
	return (result);
//	char	*pointer_to_divider;
//	char	*result;
//
//	if (!*line)
//		return (NULL);
//	result = NULL;
//	pointer_to_divider = ft_strchr(*line, DIVIDER);
//	if (pointer_to_divider == NULL || pointer_to_divider[0] == '\0'
//		|| pointer_to_divider[1] == '\0')
//	{
//		result = *line;
//		*line = NULL;
//	}
//	else
//	{
//		result = *line;
//		*line = ft_strdup(pointer_to_divider + 1);
//		pointer_to_divider[1] = '\0';
//	}
//	return (result);
}

char *cut_head_from_line(char *line)
{
	int i;
	int j;
	char	*new_line;

	i = 0;
	while (line[i] && line[i] != DIVIDER)
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new_line = (char *) malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!new_line)
		return (NULL);
	j = 0;
	while ((line[i]))
		new_line[j++] = line[i++];
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char 		*result;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	line = read_until_divider(fd, line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	result = get_head_from_line(&line);
	line = cut_head_from_line(line);
	return (result);
//	static char	*line_tail;
//	char		*read_to_divider;
//	char		*tmp_for_freeing;
//	char		*pointer_to_divider;
//	char		*new_head;
//
//	if (fd < 0 || BUFF_SIZE <= 0)
//		return (NULL);
//	new_head = cut_head_from_static(&line_tail);
//	if (new_head && ft_strchr(new_head, DIVIDER))
//		return (new_head);
//	else
//	{
//		read_to_divider = read_until_divider(fd);
//		if (new_head && read_to_divider)
//		{
//			tmp_for_freeing = read_to_divider;
//			read_to_divider = ft_strjoin(new_head, read_to_divider);
//			free(tmp_for_freeing);
//			free(new_head);
//		}
//		else if (new_head)
//			read_to_divider = new_head;
//		else if (!read_to_divider)
//			return (NULL);
//		pointer_to_divider = ft_strchr(read_to_divider, DIVIDER);
//		if (pointer_to_divider && pointer_to_divider[0] != '\0'
//			&& pointer_to_divider[1] != '\0')
//		{
//			line_tail = ft_strdup(pointer_to_divider + 1);
//			pointer_to_divider[1] = '\0';
//			return (read_to_divider);
//		}
//		else
//			return (read_to_divider);
//	}
}
