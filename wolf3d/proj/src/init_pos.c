/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:18:37 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 18:55:08 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_init_pos(t_event *e)
{
	int x;
	int y;

	x = 0;
	while (e->s->map[x])
	{
		y = 0;
		while (e->s->map[x][y])
		{
			if (e->s->map[x][y] == '/')
			{
				e->c->posx = x;
				e->c->posy = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
