/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:14:44 by xtorres-          #+#    #+#             */
/*   Updated: 2023/03/06 20:14:47 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_validate(int count, char *pid)
{
	if (count != 3)
	{
		printf("Error arguments\n");
		return (0);
	}
	while (*pid != '\0')
	{
		if (*pid >= 48 && *pid <= 57)
		{
			++pid;
			continue ;
		}
		printf("Error pid\n");
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned int	number;

	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		if (number > 2147483647)
			return (0);
		str++;
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;
	int	j;

	i = -1;
	if (ft_validate(argc, argv[1]) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (argv[2][i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j--;
		}
	}
	printf("mypid: %d\n", getpid());
	return (0);
}
