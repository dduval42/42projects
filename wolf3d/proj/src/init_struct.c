/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:16:44 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:12:48 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_event		*ft_init_struct(void)
{
	t_event *e;
	t_cam	*c;
	t_mlx	*m;
	t_ress	*s;

	e = (t_event *)malloc(sizeof(t_event));
	c = (t_cam *)malloc(sizeof(t_cam));
	m = (t_mlx *)malloc(sizeof(t_mlx));
	s = (t_ress *)malloc(sizeof(t_ress));
	e->c = c;
	e->m = m;
	e->s = s;
	c->dirx = -1.0;
	c->diry = 0.0;
	e->c->ms = 0.1;
	e->c->rs = 0.075;
	c->planex = 0.0;
	c->planey = 0.66;
	e->s->levels = 0;
	e->wintime = time(NULL);
	return (e);
}
