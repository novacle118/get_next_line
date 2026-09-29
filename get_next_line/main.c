/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadler <fstadler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:03:32 by fstadler          #+#    #+#             */
/*   Updated: 2026/07/09 15:05:56 by fstadler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*buffer;
	int		counter;

	counter = 0;
	fd = open("test.txt", O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		counter++;
		printf("%i%s", counter, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
	printf("%i", counter);
	return (0);
}
