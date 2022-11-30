#include "get_next_line.c"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int	main()
{
	int	fd;
	char *line;
	int i = 0;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	//while(line)
	//{
	//	printf("LINE: %s", line);
	//	printf("\n");
	//	line = get_next_line(fd);
	//	i++;
	//}
	printf("LINE: %s", line);
	close(fd);
	return (0);
}