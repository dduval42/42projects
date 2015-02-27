/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 20:46:33 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 19:18:30 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_draw		*ft_init_draw(t_ray *ray, int side)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	draw->lineheight = abs((int)(HAUTEUR / ray->walldist));
	draw->drawstart = -(draw->lineheight) / 2 + HAUTEUR / 2;
	if (draw->drawstart < 0)
		draw->drawstart = 0;
	draw->drawend = draw->lineheight / 2 + HAUTEUR / 2;
	if (draw->drawend >= HAUTEUR)
		draw->drawend = HAUTEUR - 1;
	if (side == 0)
		draw->color = 0xFF0000;
	else if (side == 2)
		draw->color = 0x0000FF;
	else if (side == 3)
		draw->color = 0x00FF00;
	else if (side == 1)
		draw->color = 0xFFFFFF;
	else
		draw->color = 0xFFA500;
	return (draw);
}
