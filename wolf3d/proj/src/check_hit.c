/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 20:04:53 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 20:09:43 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		ft_alt_check(t_event *e, int *hit, int *side, t_ray *ray)
{
	if ((e->s->map[ray->mapx][ray->mapy] - '0') > 0)
		*hit = 1;
	if ((e->s->map[ray->mapx][ray->mapy]) == '!')
	{
		*hit = 2;
		*side = 5;
	}
}

t_ray		*ft_check_hit(int hit, t_ray *ray, t_event *e, int *side)
{
	while (hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			*side = (ray->mapx < e->c->posx) ? 0 : 2;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			*side = (ray->mapy < e->c->posy) ? 1 : 3;
		}
		ft_alt_check(e, &hit, side, ray);
	}
	if (*side == 0 || *side == 2)
		ray->walldist = fabs((ray->mapx - ray->rayposx +
		(1 - ray->stepx) / 2) / ray->raydirx);
	else
		ray->walldist = fabs((ray->mapy - ray->rayposy +
		(1 - ray->stepy) / 2) / ray->raydiry);
	return (ray);
}
