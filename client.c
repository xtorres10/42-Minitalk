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

// int	validate(char *argv)
// {
// 	printf(argv[1]);
// 	return (-1);
// }

int	ft_atoi(const char *str)
{
	int				signal;
	unsigned long	number;

	signal = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		if (number > 9223372036854775808UL && signal == -1)
			return (0);
		if (number > 9223372036854775807UL && signal == 1)
			return (-1);
		str++;
	}
	return (number * signal);
}

// int	ft_num_tobinary(int	num)
// {
// 	int	bnum;

	
// }

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;
	int	j;

	i = -1;
	if (argc != 3)
	{
		printf("Error");
		return (0);
	}
	while (argv[1][++i] != '\0')
	{
		if (argv[1][i] >= 48 && argv[1][i] <= 57)
			continue ;
		printf("Error");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	// printf("%d\t", 11 & (1u << 7)); // 10000000
	// printf("%d\t", 11 & (1u << 6)); // 01000000
	// printf("%d\t", 11 & (1u << 5)); // 00100000
	// printf("%d\t", 11 & (1u << 4)); // 00010000
	// printf("%d\t", 11 & (1u << 3)); // 00001000
	// printf("%d\t", 11 & (1u << 2)); // 00000100
	// printf("%d\t", 11 & (1u << 1)); // 00000010
	// printf("%d\t", 11 & (1u << 0)); // 00000001

// 11 = 00001011

	i = -1;
	while (argv[2][++i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (argv[2][i] & (1u << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
		}
	}
}
