/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:09:53 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:31:13 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		ft_len_map(t_event *e)
{
	int		fd;
	int		len;
	char	*error;
	char	*t;
	char	*str;

	len = 0;
	fd = open(e->s->argv, O_RDONLY);
	if (fd == -1)
	{
		t = ft_strrchr(e->s->argv, '/') + 1;
		error = ft_strjoin(t, " : can't be find, wolf3d have to quit.\n", NONE);
		ft_putstr_fd(error, 2);
		free(error);
		free(e->s->argv);
		exit (EXIT_FAILURE);
	}
	while (get_next_line(fd, &str) > 0)
	{
		free(str);
		len++;
	}
	close (fd);
	return (len);
}
