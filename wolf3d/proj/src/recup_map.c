/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:51:27 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:36:31 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

char	**ft_recup_map(t_event *e)
{
	char	**map;
	int		len;
	int		fd;
	char	*str;

	len = ft_len_map(e);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	map[len] = NULL;
	len = 0;
	fd = open(e->s->argv, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		map[len++] = ft_strdup(str);
		free(str);
	}
	close(fd);
	return (map);
}
