/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:33:54 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:30:47 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_draw	*ft_init_ray(t_cam *c, double cam, t_event *e)
{
	t_ray	*ray;
	t_draw	*draw;
	int		side;

	side = 0;
	ray = (t_ray *)malloc(sizeof(t_ray));
	ray->rayposy = c->posy;
	ray->rayposx = c->posx;
	ray->raydirx = c->dirx + c->planex * cam;
	ray->raydiry = c->diry + c->planey * cam;
	ray->deltadistx = sqrt(1 + ((ray->raydiry * ray->raydiry) /
		(ray->raydirx * ray->raydirx)));
	ray->deltadisty = sqrt(1 + ((ray->raydirx * ray->raydirx) /
		(ray->raydiry * ray->raydiry)));
	ray->mapx = (int)ray->rayposx;
	ray->mapy = (int)ray->rayposy;
	ray = ft_check_step(ray);
	ray = ft_check_hit(0, ray, e, &side);
	draw = ft_init_draw(ray, side);
	free(ray);
	return (draw);
}
