#include "ft_traceroute.h"

t_ts	ft_get_ts(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
