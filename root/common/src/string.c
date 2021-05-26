#include <stdlib.h>

#include "minitalk.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sstr;
	unsigned char	*dstr;

	i = 0;
	sstr = (unsigned char *)src;
	dstr = dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dstr[i] = sstr[i];
		++i;
	}
	return (dst);
}

static char	*ft_strdup(const char *s1)
{
	char	*pointer;
	size_t	size;
	int		i;

	size = ft_strlen(s1) + 1;
	pointer = malloc(size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = 0;
	return (pointer);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = 0;
	return (str);
}

char	**str_cappend(char **container, char c)
{
	char	*tmp;
	char	char_to_str[2];

	if (!container)
		return (NULL);
	tmp = *container;
	char_to_str[0] = c;
	char_to_str[1] = 0;
	*container = ft_strjoin(tmp, char_to_str);
	free(tmp);
	if (!*container)
		return (NULL);
	return (container);
}

char	**str_new(void)
{
	char	**string;

	string = malloc(sizeof(char *));
	if (!string)
		return (NULL);
	*string = ft_strdup("");
	if (!*string)
	{
		free(string);
		return (NULL);
	}
	return (string);
}
