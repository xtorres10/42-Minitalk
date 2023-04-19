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
#include <stdlib.h> 

int	ft_validate(int count, char *pid)
{
	if (count != 3)
		return (write(1, "Error arguments\n", 17));
	while (*pid != '\0')
	{
		if (*pid >= 48 && *pid <= 57)
		{
			++pid;
			continue ;
		}
		return (write(1, "Error pid\n", 10));
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		if (number > 2147483647)
			return (1);
		str++;
	}
	return (number);
}

void	ft_do_anything(int sig)
{
	if (sig == SIGUSR2)
		return ;
}

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	int					j;
	struct sigaction	action;

	action.sa_handler = ft_do_anything;
	i = -1;
	if (ft_validate(argc, argv[1]) != 0)
		return (1);
	pid = ft_atoi(argv[1]);
	while (argv[2][++i] != '\0')
	{
		j = 8;
		while (--j >= 0)
		{
			if (argv[2][i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (sigaction(SIGUSR2, &action, NULL) < 0)
				exit(1);
			usleep(200);
		}
	}
	return (0);
}
