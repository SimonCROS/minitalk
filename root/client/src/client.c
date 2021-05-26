#include <stdlib.h>
#include <signal.h>

#include "minitalk.h"

static int	send_letter(pid_t target, char c)
{
	int	i;
	int	sig;

	i = 8;
	while (i > 0)
	{
		i--;
		if (((c >> i) & 1))
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
		if (kill(target, sig) == -1)
			return (0);
		usleep(100);
	}
	return (1);
}

static int	send_string(pid_t target, char *str)
{
	while (*str)
		if (!send_letter(target, *(str++)))
			return (0);
	if (!send_letter(target, 0))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		is_valid;

	if (argc != 3)
		return (EXIT_FAILURE);
	is_valid = ft_atoi(argv[1], &pid);
	if (!is_valid)
		return (EXIT_FAILURE);
	if (!send_string(pid, argv[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
