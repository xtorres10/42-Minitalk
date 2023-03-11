#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// void	ft_bnum_todecimal(char *num)
// {
// 	int	dnum;
// 	int	i;

// 	i = 7;
// 	dnum = 0;
// 	while (i >= 0)
// 	{
// 		dnum += (num[i] - 48) << (7 - i);
// 		i--;
// 	}
// 	printf("%d\n", dnum);
// 	// write(1, &dnum, 1);
// }

void	handler_signal(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		printf("x");
	// static int	i;
	// static char	bnum[8];

	// i = 0;
	// printf("sig: %d\n", i);
	// while (i < 8)
	// {
	// 	if (sig == SIGUSR1)
	// 		bnum[i] = '1';
	// 	if (sig == SIGUSR2)
	// 		bnum[i] = '0';
	// 	i++;
	// }
	// ft_bnum_todecimal(bnum);
	// i = 0;
}
int con = 0;
int	main(void)
{
	struct sigaction	sact;
	// //sigset_t			sigset;

	// printf("pid: %d\n", getpid());
	// // sigemptyset(&sigset);
	// sact.sa_handler = handler_signal;
	// // // sigaddset(&sigset, SIGUSR1);
	// // // sigaddset(&sigset, SIGUSR2);
	// sigaction(SIGUSR1, &sact, NULL);
	// printf("1");
	// sigaction(SIGUSR2, &sact, NULL);
	printf("pid: %d\n", getpid());

	while (1)
	{
		sact.sa_handler = handler_signal;
		sigaction(SIGUSR1, &sact, NULL);
		sigaction(SIGUSR2, &sact, NULL);	
		pause();
	}
	return (0);
}