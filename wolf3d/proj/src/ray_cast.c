/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:29:53 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:38:46 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	draw_line(int x, t_event *e)
{
	int i;
	int y1;
	int y2;
	int color;

	y1 = e->draw->drawstart;
	y2 = e->draw->drawend;
	color = e->draw->color;
	i = 0;
	while (i < y1)
		mlx_pixel_put_to_image(0x4BB5C1, e, x, i++);
	while (y1 < y2)
	{
		mlx_pixel_put_to_image(color, e, x, y1);
		y1++;
	}
	i = y2;
	while (i < HAUTEUR)
		mlx_pixel_put_to_image(0xCCCCCC, e, x, i++);
}

t_event *ft_ray_cast(t_event *e)
{
	int		x;
	double	cam;
	t_draw	*draw;

	x = 0;
	ft_get_fps(e);
	e->m->img = mlx_new_image(e->m->mlx, LARGEUR, HAUTEUR);
	e->m->data = mlx_get_data_addr(e->m->img, &(e->m->bpp),
		&(e->m->size), &(e->m->endian));
	while (x < LARGEUR)
	{
		cam = 2.0 * x / (double)LARGEUR - 1.0;
		draw = ft_init_ray(e->c, cam, e);
		e->draw = draw;
		draw_line(x, e);
		free(e->draw);
		x++;
	}
	mlx_put_image_to_window(e->m->mlx, e->m->win, e->m->img, 0, 0);
	mlx_destroy_image(e->m->mlx, e->m->img);
	return (e);
}
