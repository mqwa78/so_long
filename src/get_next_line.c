#include "../includes/so_long.h"

char	*ft_new_storage(char *storage)
{
	char	*new_storage;
	size_t	i;
	size_t	j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(sizeof(char) * (gnl_strlen(storage) - i + 1));
	if (!new_storage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*ft_create_line(char *storage, t_map *map)
{
	char	*line;
	size_t	i;

	if (!*storage)
		return (NULL);
	line = malloc(sizeof(char) * ft_count_char(storage) + 2);
	if (!line)
	{
		free(storage);
		ft_error(map, 3);
	}
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_fill_tab(char *storage, int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_check_endline(storage) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		storage = gnl_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd, t_map *map)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		ft_error(map, 1);
	storage = ft_fill_tab(storage, fd);
	if (!storage)
		ft_error(map, 2);
	line = ft_create_line(storage, map);
	if (!ft_check_line(line))
	{
		free(line);
		free(storage);
		ft_error(map, 4);
	}
	storage = ft_new_storage(storage);
	return (line);
}
