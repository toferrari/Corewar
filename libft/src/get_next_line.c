/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:34:33 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 10:50:12 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strchr_index(const char *s, char c)
{
	int					i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

static int		save_in_line(char **line, int index, char *buff, char **tmp)
{
	char				*save;

	*line = (index) ? (ft_strsub(buff, 0, index)) : (ft_strdup(""));
	if (line == NULL)
		return (-1);
	save = *tmp;
	if (ft_strlen(buff + index + 1))
	{
		*tmp = ft_strdup(buff + index + 1);
		if (*tmp == NULL)
			return (1);
	}
	else
		*tmp = 0;
	if (save)
		free(save);
	return (0);
}

static int		empty_tmp(int fd, char **line, char **tmp)
{
	int					len;
	int					index;
	char				buff[BUF_SZ + 1];

	len = read(fd, buff, BUF_SZ);
	buff[len] = '\0';
	if (len < 1)
		return (len);
	if ((index = ft_strchr_index(buff, '\n')) != -1)
		return (save_in_line(line, index, buff, &(tmp[fd])) ? -1 : 1);
	if ((tmp[fd] = ft_strdup(buff)) == NULL)
		return (-1);
	return (get_next_line(fd, line));
}

static int		not_empty_tmp(int fd, char **line, char **tmp)
{
	int					len;
	char				buff[BUF_SZ + 1];
	char				*save;
	int					index;

	if ((index = ft_strchr_index(tmp[fd], '\n')) != -1)
		return (save_in_line(line, index, tmp[fd], &(tmp[fd])) ? -1 : 1);
	else
	{
		len = read(fd, buff, BUF_SZ);
		buff[len] = '\0';
		if (len < 0)
			return (-1);
		else if (!len)
		{
			*line = ft_strdup(tmp[fd]);
			free(tmp[fd]);
			tmp[fd] = 0;
			return (1);
		}
		save = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		free(save);
		return (get_next_line(fd, line));
	}
}

int				get_next_line(const int fd, char **line)
{
	static char		*tmp[5000];

	if (fd < 0 || fd > 4999)
		return (-1);
	if (!tmp[fd])
		return (empty_tmp(fd, line, tmp));
	else
		return (not_empty_tmp(fd, line, tmp));
}
