/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:26:24 by xtorres-          #+#    #+#             */
/*   Updated: 2023/04/08 19:26:30 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_bnum_todecimal(char *num)
{
	int	dnum;
	int	i;

	i = 7;
	dnum = 0;
	while (i >= 0)
	{
		dnum += (num[i] - 48) << (7 - i);
		i--;
	}
	write(1, &dnum, 1);
}

void	handler_signal(int sig)
{
	static int	i = 0;
	static char	bnum[8];

	if (sig == SIGUSR1)
		bnum[i] = '1';
	else if (sig == SIGUSR2)
		bnum[i] = '0';
	i++;
	if (i == 8)
	{
		ft_bnum_todecimal(bnum);
		i = 0;
	}
}

int	main(void)
{
	// struct sigaction	sact;
	// sigset_ t			sigset;

	printf("pid: %d\n", getpid()); 
	// sigemptyset(&sigset);
	// sact.sa_handler = handler_signal;
	// sigaddset(&sigset, SIGUSR1);
	// sigaddset(&sigset, SIGUSR2);
	// sigaction(SIGUSR1, &sact, NULL);
	// sigaction(SIGUSR2, &sact, NULL);
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
