/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:59:25 by hehuang           #+#    #+#             */
/*   Updated: 2024/06/30 18:08:55 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>

int	ft_check_param(const char *nptr, int min, int max)
{
	int					i;
	unsigned long long	res;

	res = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		if (res > 2147483647)
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	else if (min > 0 && (int) res < min)
		return (0);
	else if (max > 0 && (int) res > max)
		return (0);
	return (1);
}

void	ft_puttime_fd(size_t n, int fd)
{
	unsigned long long	nl;
	char				c;

	nl = (unsigned long long)n;
	if (nl >= 10)
		ft_puttime_fd((nl / 10), fd);
	c = (nl % 10) + '0';
	write (fd, &c, 1);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
