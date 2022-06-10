# better_gnl
I am speed

This a revamped version of the project get_next_line.

Admittedly my first attempt (two years ago at the time of writing) was neither fast nor efficient.
You can look at the old code here(https://github.com/42Curriculum/ft_get_next_line)

The old version used many many many calls to strjoin and therefore allocated and reallocated a lot of memory. It also had to copy nearly as many times as it allocated.

The new and improved version does at most 1 allocation (necessary as per the project's guidelines, the returned line must be allocated) and 2 copies (altough if it wasn't for the restrictions on line count, the minimum would be 1 copy).
per iterations.

### How it works
<details>
  <summary>If you are doing GNL for the first time, please figure it out by yourself first :)</summary>
This rakes advantage of the fact that arrays are contiguous pieces of memory. While the subject precises that we can only have buffers and read BUFF_SIZE, allocating multiple of such buffers together gives us one big continuous buffer in the form `char	(*buffers)[BUFF_SIZE];` This can be allocated as a single buffer of BUFF_SIZE * bufferCount;
</details>
  
Then we can read chunks of BUFF_SIZE in an easy way without pointer artihmetic. We can iteratatre through buffers like a normal char array until we fin /n and change it into a /0 and allocate that much memory and do a single copy from buffers into the newly allocated line. and shift(copy the whole buffer array into the beginning) our array. Rinse and repeat until there is nothing left to read

*I challenge any and all who would dare defy the superiority of this get_next_line.*

**Race me, I dare you**

Note: I forgot to check for leaks and I don't think I freed things so :)
