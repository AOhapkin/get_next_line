#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("READ_THIS", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
	}
	// line = get_next_line(fd);
	free(line);
	return (0);
}
