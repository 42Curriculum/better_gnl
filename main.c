#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line);

int main()
{
	char *str;


	str = NULL;
	int fd = open("test.txt", O_RDONLY);
	// printf("returned %d",get_next_line(1,&str));
	while(get_next_line(fd, &str) > 0)
		printf("LINE %s\n", str);
	printf("LINE %s\n", str);
}
