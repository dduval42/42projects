/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:42:26 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:26:17 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			find_nl(char *str)
{
	char	*bak;

	bak = str;
	if (str)
	{
		while (*str)
		{
			if (*str == EOF)
				return (str - bak - 1);
			if (*str++ == '\n')
				return (str - bak - 1);
		}
	}
	return (-1);
}

static char			*get_next_nl(char **str)
{
	int		pos;
	int		len;
	char	*ret;
	char	*bak;

	if ((pos = find_nl(*str)) == -1)
		return (NULL);
	if (!(ret = (char *)malloc((pos + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	while ((ret - bak) < pos)
		*ret++ = *((*str)++);
	*ret = 0;
	len = ft_strlen(*str);
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	while (**str)
		*ret++ = *(++(*str));
	free(*str - len - pos);
	*str = ret - len;
	return (bak);
}

static char			*concat_string(char *old, char *buf, int n)
{
	char	*ret;
	char	*bak;

	if (!(ret = (char *)malloc((ft_strlen(old) + n + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	if (old)
	{
		while (*old)
			*ret++ = *old++;
	}
	*(ret + n) = 0;
	free(old - (ret - bak));
	while (n--)
		*(ret + n) = buf[n];
	return (bak);
}

int					get_next_line(int fd, char **line)
{
	char		*ret;
	int			nb_read;
	static char	*old;
	char		buf[BUFF_SIZE];

	while (!(ret = get_next_nl(&old)))
	{
		nb_read = read(fd, buf, BUFF_SIZE);
		if (!nb_read)
		{
			ret = old;
			*line = ret;
			return (0);
		}
		else if (nb_read == -1)
		{
			**line = '\0';
			return (-1);
		}
		old = concat_string(old, buf, nb_read);
	}
	*line = ret;
	return (1);
}
