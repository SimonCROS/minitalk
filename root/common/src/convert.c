int	ft_atoi(char *str, int *result)
{
	int	ret;
	int	mul;

	ret = 0;
	mul = 1;
	if (*str == '-')
	{
		str++;
		mul = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	*result = ret * mul;
	return (!(*str));
}
