# better_gnl
I am speed

This a revamped version of the project get_next_line.

Admittedly my first attempt (two years ago at the time of writing) was neither fast nor efficient.
You can look at the old code here(https://github.com/42Curriculum/ft_get_next_line)

The old version used many many many calls to strjoin and therefore allocated and reallocated a lot of memory. It also had to copy nearly as many times as it allocated.

The new and improved version does at most 1 allocation (necessary as per the project's guidelines, the returned line must be allocated) and 2 copies (altough if it wasn't for the restrictions on line count, the minimum would be 1 copy).
per iterations.

*I challenge any and all who would dare defy the superiority of this get_next_line.*

**Race me, I dare you**
