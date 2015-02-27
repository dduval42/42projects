/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:32:44 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:32:51 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	mlx_pixel_put_to_image(unsigned long color, t_event *e, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (color & 0xFF0000) >> 16;
	color2 = (color & 0xFF00) >> 8;
	color3 = (color & 0xFF) >> 0;
	e->m->data[y * e->m->size + x * e->m->bpp / 8] = color3;
	e->m->data[y * e->m->size + x * e->m->bpp / 8 + 1] = color2;
	e->m->data[y * e->m->size + x * e->m->bpp / 8 + 2] = color1;
}
