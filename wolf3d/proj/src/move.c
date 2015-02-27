/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:17:23 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:31:35 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_move_up_down(int key, t_event *e)
{
	int pos[4];

	pos[0] = (int)(e->c->posx + e->c->dirx * e->c->ms);
	pos[1] = (int)(e->c->posy + e->c->diry * e->c->ms);
	pos[2] = (int)(e->c->posx - e->c->dirx * e->c->ms);
	pos[3] = (int)(e->c->posy - e->c->diry * e->c->ms);
	if (key == UP)
	{
		if (e->s->map[pos[0]][(int)(e->c->posy)] - '0' < 1)
			e->c->posx += e->c->dirx * e->c->ms;
		if (e->s->map[(int)(e->c->posx)][pos[1]] - '0' < 1)
			e->c->posy += e->c->diry * e->c->ms;
	}
	if (key == DOWN)
	{
		if (e->s->map[pos[2]][(int)(e->c->posy)] - '0' < 1)
			e->c->posx -= e->c->dirx * e->c->ms;
		if (e->s->map[(int)(e->c->posx)][pos[3]] - '0' < 1)
			e->c->posy -= e->c->diry * e->c->ms;
	}
}

void	ft_move_left_right(int key, t_event *e)
{
	double	olddirx;
	double	oldplanex;
	t_cam	*c;

	c = e->c;
	olddirx = c->dirx;
	oldplanex = c->planex;
	if (key == RIGHT)
	{
		c->dirx = c->dirx * cos(-(c->rs)) - c->diry * sin(-(c->rs));
		c->diry = olddirx * sin(-(c->rs)) + c->diry * cos(-(e->c->rs));
		c->planex = c->planex * cos(-(c->rs)) - c->planey * sin(-(c->rs));
		c->planey = oldplanex * sin(-(c->rs)) + c->planey * cos(-(c->rs));
	}
	if (key == LEFT)
	{
		c->dirx = c->dirx * cos(c->rs) - c->diry * sin(c->rs);
		c->diry = olddirx * sin(c->rs) + c->diry * cos(c->rs);
		c->planex = c->planex * cos(c->rs) - c->planey * sin(c->rs);
		c->planey = oldplanex * sin(c->rs) + c->planey * cos(c->rs);
	}
}
