#include <stdlib.h>
#include <signal.h>

#include "minitalk.h"

static void	signal_recived(int signum)
{
	static char	**str;
	static int	bit = 0;
	static char	c = 0;

	if (bit == 0 && !str)
		str = str_new();
	if (!str)
		return ;
	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	if (++bit == 8)
	{
		if (c)
			str = str_cappend(str, c);
		else
		{
			ft_putendl(*str);
			free(*str);
			free(str);
			str = NULL;
		}
		bit = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, signal_recived);
	signal(SIGUSR2, signal_recived);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
