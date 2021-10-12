#ifndef GNL_H
# define GNL_H

# define BUFF_SIZE 10
#ifndef NULL
	# define NULL ((void *)0)
#endif

typedef struct gnl_buff
{
	char	(*buffers)[BUFF_SIZE];
	int		bufferMax;
	int		start;
	int		_start;
}				gnl_buff;

#endif
