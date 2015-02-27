/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:01:10 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:29:40 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_get_fps(t_event *e)
{
	static	double	curtime;
	static	double	oldtime;
	static	int		fps;
	static	int		countframe;
	char			*speedstr;

	curtime = (double)clock();
	if (countframe == 0)
		oldtime = curtime;
	countframe++;
	if (countframe == 10)
	{
		fps = ceil(10.0 / ((curtime - oldtime) / 1000000));
		curtime = 0;
		countframe = 0;
	}
	speedstr = ft_strjoin("FPS : ", ft_itoa(fps), SEC);
	mlx_string_put(e->m->mlx, e->m->win, 10, 10, 0x000000, speedstr);
	free(speedstr);
	speedstr = ft_strjoin("movespeed = ", ft_itoa((int)(e->c->ms * 100)), SEC);
	speedstr = ft_strjoin(speedstr, " rotatespeed = ", FIRST);
	speedstr = ft_strjoin(speedstr, ft_itoa((int)(e->c->rs * 100)), BOTH);
	mlx_string_put(e->m->mlx, e->m->win, 10, 30, 0X000000, speedstr);
	free(speedstr);
}
