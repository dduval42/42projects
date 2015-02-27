/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:54:07 by dduval            #+#    #+#             */
/*   Updated: 2015/02/13 12:15:13 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fract.h>


t_coord	ft_init(void)
{
	t_coord e;

	e.x = 0;
	e.y = 0;
	e.a = 0;
	e.rc = 0.0;
	e.ic = 0.0;
	e.rz = 0.0;
	e.iz = 0.0;
	e.r = 0.0;
	e.i = 0.0;
	e.iter = 50;
	e.maxxm = 1;
	e.minxm = -1;
	e.minxj = -1;
	e.maxxj = 1;
	e.miny = -1;
	e.maxy = 1;
	e.h = 1;
	return (e);
}

void	mlx_pixel_put_to_image(unsigned long img_color, t_coord e)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (img_color & 0xFF0000) >> 16;
	color2 = (img_color & 0xFF00) >> 8;
	color3 = (img_color & 0xFF) >> 0;
	e.data[e.y * e.sizeline + e.x * e.bpp / 8 ] = color3;
	e.data[e.y * e.sizeline + e.x * e.bpp / 8 + 1] = color2;
	e.data[e.y * e.sizeline + e.x * e.bpp / 8 + 2] = color1;
}

t_coord	ft_fractale( t_coord e)
{
	while(e.x < LARGEUR)
	{
		e.y = 0;
		while (e.y < HAUTEUR)
		{
			e.rz = 0.0;
			e.iz = 0.0;
			e.rc = e.x / (LARGEUR / (e.maxxm - e.minxm)) + e.minxm;
			e.ic = e.y / ( HAUTEUR / (e.maxy -e.miny)) + e.miny;
			e.a = 0;
			while (e.a < e.iter)
			{
				e.r = e.rz;
				e.i = e.iz;
				e.rz = e.r*e.r - e.i*e.i + e.rc;
				e.iz = 2* e.r*e.i + e.ic;
				if ((e.rz * e.rz + e.iz * e.iz) >= 4)
					break;
				e.a++;
			}
			if (e.a < e.iter)
				mlx_pixel_put_to_image(e.a * 0xFF00FF / (e.iter - 1), e);
			e.y++;
		}
		e.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	return (e);
}

void	ft_fractale2(t_coord e)
{
	while(e.x < LARGEUR)
	{
		e.y = 0;
		while (e.y < HAUTEUR)
		{
			e.iz = e.y / (HAUTEUR / (e.maxy -  e.miny)) +  e.miny;
			e.rz = e.x / (LARGEUR / (e.maxxj - e.minxj)) + e.minxj;
			e.rc = 0.3;
			e.ic = 0.5;
			e.a = 0;
			while (e.a < ( 5 * e.iter))
			{
				e.r = e.rz;
				e.i = e.iz;
				e.rz = e.r*e.r - e.i*e.i + e.rc;
				e.iz = 2* e.r*e.i + e.ic;
				if ((e.rz * e.rz + e.iz * e.iz) >= 4)
					break;
				e.a++;
			}
			if (e.a < (5 * e.iter))
				mlx_pixel_put_to_image((e.a * 255 / (e.iter - 1)), e);
			e.y++;
		}
		e.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_coord	e;

	argc = argc;
	e = ft_init();
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, LARGEUR, HAUTEUR, "fract\'ol");
	e.img = mlx_new_image (e.mlx, LARGEUR, HAUTEUR);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sizeline), &(e.endian));
	e.argv = argv;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose, &e);
	mlx_loop(e.mlx);
	return EXIT_SUCCESS;
}
