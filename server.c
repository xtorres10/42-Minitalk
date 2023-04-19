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
#include <stdlib.h> 

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

void	handler_signal(int sig, siginfo_t *info, void *notused)
{
	static int	i;
	static int	num;

	(void)notused;
	(void)info;
	if (sig == SIGUSR1)
		num += 1 << (7 - i);
	else if (sig == SIGUSR2)
		num += 0 << (7 - i);
	i++;
	if (i == 8)
	{
		write(1, &num, 1);
		i = 0;
		num = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sact;
	sigset_t			sigset;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&sigset);
	sact.sa_sigaction = handler_signal;
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	if (sigaction(SIGUSR1, &sact, NULL) == -1)
		exit(1);
	else if (sigaction(SIGUSR2, &sact, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
