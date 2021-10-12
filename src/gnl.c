#include <unistd.h>
#include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

#include "../includes/gnl.h" // This because vsCode gives me ugly error messages even though I KNOW IT KNOWS WHERE TO FIND THIS
# define FD_MAX 1023 // Seems to be the soft limit for FD. apprently varies by os and machine so I'm leaving it at 1023

void	ft_memcpy(void *dst, void *src, size_t n);

void	grow_buffers(gnl_buff *file)
{
	gnl_buff tmp;

	file->bufferMax *= 2;
	tmp = *file;
	file->buffers = malloc(file->bufferMax * sizeof(char (*)[BUFF_SIZE + 1]));
	ft_memcpy(file, &tmp, sizeof(gnl_buff));
}

int		search(char *str, int start, int size, int *total)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\0')
			return -1;
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
		*total += 1;
	}
	return (i == size) ? (0) : (i + start + 1);
}

int		season1_part1(int *total, int *i, gnl_buff *file, char **line)
{
	*total = 0;
	*i = 0;
	if (file->bufferMax == 0)
	{
		file->buffers = malloc(1 * sizeof(*file->buffers));
		file->bufferMax = 1;
		file->start = 0;
	}
	else
	{
		if ((file->_start = search(file->buffers[*i] + file->start, file->start,\
		BUFF_SIZE - file->start, total)))
		{
				*line = malloc(*total + 1);
				ft_memcpy(*line, &file->buffers[0][file->start], *total);
				file->start = file->_start;
				return file->_start != -1;
		}
		else if (++*i && *i >= file->bufferMax)
			grow_buffers(file);
	}
	return 2;
}
//Not sure if file ends with \n or EOF?
int		get_next_line(const int fd, char **line)
{
	static gnl_buff file[FD_MAX];
	int 	b;
	int 	i;
	int		total;

	if (fd < 0 || fd > FD_MAX || line == NULL)
		return -1;
	if ((b = season1_part1(&total, &i, &file[fd], line)) == 2)
	{
		while ((b = read(fd, file[fd].buffers[i], BUFF_SIZE)))
		{
			(b < BUFF_SIZE) ?  file[fd].buffers[i][b - 1] = '\0' : -1;
			if ((file[fd]._start = search(file[fd].buffers[i], 0, b, &total)) != 0)
			{
				*line = malloc(total + 1);
				ft_memcpy(*line, &file[fd].buffers[0][file[fd].start], total);
				ft_memcpy(file[fd].buffers, file[fd].buffers[i], b);
				file[fd].start = file[fd]._start;
				return file[fd]._start != -1;
			}
			if (++i >= file[fd].bufferMax)
				grow_buffers(&file[fd]);
		}
	}
	return b;
}

