/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:33:27 by marvin            #+#    #+#             */
/*   Updated: 2021/12/10 10:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buff(char **buff, char **str)
{
	free(*buff);
	free(*str);
}

char	*read_from_file(int fd, char *buff)
{
	char	*str;
	int		bytes;

	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	bytes = BUFFER_SIZE;
	while (!ft_strchr_gnl(buff, '\n') && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			return (NULL);
		}
		str[bytes] = '\0';
		buff = ft_strjoin_gnl(buff, str);
		if (!buff)
		{
			clean_buff(&buff, &str);
			return (NULL);
		}
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_from_file(fd, buff);
	if (!buff)
		return (NULL);
	result = get_line(buff);
	buff = work_with_buff(buff);
	return (result);
}
