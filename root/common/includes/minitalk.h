#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>

/*** String utils *************************************************************/

unsigned int	ft_atoi(char *str, int *result);
unsigned int	ft_strlen(const char *s);
ssize_t			ft_putchar(const char c);
ssize_t			ft_putnbr(const unsigned int n);
ssize_t			ft_putendl(const char *s);
ssize_t			ft_putstr(const char *s);
char			**str_cappend(char **container, char c);
char			**str_new(void);

#endif
