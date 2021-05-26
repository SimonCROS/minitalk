#include <unistd.h>

#include "minitalk.h"

ssize_t	ft_putchar(const char c)
{
	if (c)
		return (write(1, &c, 1));
	return (0);
}

ssize_t	ft_putstr(const char *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	return (0);
}

ssize_t	ft_putendl(const char *s)
{
	return (ft_putstr(s) + ft_putchar('\n'));
}

ssize_t	ft_putnbr(const unsigned int n)
{
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
