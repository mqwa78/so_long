
#include "../includes/so_long.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_count_char(const char *str)
{
	size_t	count;
	
	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (count);
}

BOOL	ft_check_endline(const char *str)
{	
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*gnl_strjoin(char *storage, char *buffer)
{
	char	*new_storage;
	int		i;
	size_t	j;

	if (!storage)
	{
		storage = malloc(sizeof(char) * 1);
		*storage = '\0';
	}
	if (!storage || !buffer)
		return (NULL);
	new_storage = malloc(sizeof(char) * (gnl_strlen(storage) + gnl_strlen(buffer) + 1));
	if (!new_storage)
		return (NULL);
	i = -1;
	while (storage[++i])
		new_storage[i] = storage[i];
	j = 0;
	while (buffer[j])
		new_storage[i++] = buffer[j++];
	new_storage[gnl_strlen(storage) + gnl_strlen(buffer)] = '\0';
	free(storage);
	return (new_storage);
}