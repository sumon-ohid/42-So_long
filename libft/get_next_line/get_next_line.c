/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:57:24 by sumon             #+#    #+#             */
/*   Updated: 2023/11/16 21:55:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!(str))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
	{
		str[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

size_t	clean_line(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	result = 0;
	while (buffer[i])
	{
		if (result)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			result = 1;
		buffer[i] = 0;
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (clean_line(buffer) == 1)
			break ;
		if (read(fd, buffer, BUFFER_SIZE) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;
	
// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		printf("Error\n");
// 	while (i++ < 15)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

//testing Other functions from libft

// int main()
// {
//     ft_printf("This is testing ft_printf function.\n");
//     char    str[]   = "12345";
//     int     res     = ft_atoi(str);
//     ft_printf("This is testing ft_atoi from libft : %d\n", res);
//     return (0);
// }