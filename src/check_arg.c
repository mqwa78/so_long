
#include "../includes/so_long.h"

int	ft_check_suf(char *str, int pos)
{	
	char	*buf;
	int		i;

	buf = "reb.";
	i = 0;
	while (buf[i])
	{
		if (buf[i] != str[pos])
			return (0);
		i++;
		pos--;
	}
	return (1);
}

int	ft_check_arg(char *str)
{	
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (0);
	i--;
	if (!ft_check_suf(str, i))
		return (0);
	return (1);
}