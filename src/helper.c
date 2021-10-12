#include <stddef.h>

void	ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;
	char *_dst;
	char *_src;

	i = 0;
	_dst = dst;
	_src = src;
	while (i < n)
	{
		_dst[i] = _src[i];
		i++;
	}
}
