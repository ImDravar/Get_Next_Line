#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
char *get_next_line(int fd);

int	main(void)
{
	int fd = open("hola.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
