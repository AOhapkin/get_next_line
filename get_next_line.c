#include "get_next_line.h"
#include "stdio.h"


char	*get_next_line(int fd)
{
	int 	i = 0;
	char	*buff;

	while (i < BUFFER_SIZE) {
		buff[i++] = 0;
	}
	ssize_t read_bytes = read(fd, buff, BUFFER_SIZE);
	printf("Прочитано %li байт\nВот что прочитано: \"%s\"", read_bytes, buff);
	return buff;
}