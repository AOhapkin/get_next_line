/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:52:06 by gmyriah           #+#    #+#             */
/*   Updated: 2021/11/27 14:52:06 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("READ_THIS", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("||%s||\n", line);
		free(line);
	}
	return (0);
}
