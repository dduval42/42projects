/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:42:26 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:22 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			ft_get_one(int fd, int j, char **line, char *dest)
{
	static int		i;
	static int		ret;
	static char		buf[BUFF_SIZE];

	while (i != -1)
	{
		if (i == 0 && (ret = read (fd, buf, BUFF_SIZE)) <= 0)
			i = -1;
		else
		{
			while (i < ret)
			{
				dest[j++] = buf[i++];
				if (buf[i - 1] == '\n' || i == 2)
				{
					dest[j - 1] = '\0';
					*line = dest;
					return (1);
				}
			}
			i = 0;
		}
	}
	i = 0;
	*line = dest;
	return (ret);
}

static int			ft_get(int fd, int j, char **line, char *dest)
{
	static int		i;
	static int		ret;
	static char		buf[BUFF_SIZE];

	while (i != -1)
	{
		if (i == 0 && (ret = read (fd, buf, BUFF_SIZE)) <= 0)
			i = -1;
		else
		{
			while (i < ret)
			{
				dest[j++] = buf[i++];
				if (buf[i - 1] == '\n' || i == BUFF_SIZE + 1)
				{
					dest[j - 1] = '\0';
					*line = dest;
					return (1);
				}
			}
			i = 0;
		}
	}
	i = 0;
	*line = dest;
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	char			*dest;
	int				j;
	int				i;

	j = 0;
	if (BUFF_SIZE == 1)
	{
		dest = ft_strnew (2);
		i = ft_get_one (fd, j, line, dest);
	}
	else
	{
		dest = ft_strnew (BUFF_SIZE);
		i = ft_get(fd, j, line, dest);
	}
	if (dest == NULL || i < 0)
		return (-1);
	return (i);
}
