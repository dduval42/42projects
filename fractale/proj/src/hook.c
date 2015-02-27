/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 19:55:22 by dduval            #+#    #+#             */
/*   Updated: 2015/02/13 12:14:15 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract.h>

int		key_hook(int key, t_coord *e)
{
	printf("key = %d\n", key);
	if (key == K_ESCAPE)
		exit(0);
	else if (key == K_PGDWN)
	{
		e->h *= 2;
		e->iter -= 50;
		e->minxm = -0.743643887037151 - e->h;
		e->maxxm = -0.743643887037151 + e->h;
		e->miny  = 0.13182590420533  - e->h;
		e->maxy  = 0.13182590420533 + e->h;
	}
	else if (key == K_PGUP)
	{
		e->h /= 2;
		*e = ft_zoom(*e);
		e->minxm = -0.743643887037151 - e->h;
		e->maxxm = -0.743643887037151  + e->h;
		e->miny  = 0.13182590420533 - e->h;
		e->maxy  = 0.13182590420533 + e->h;
	}
	else if (key == K_RIGHT)
	{
		e->maxxm += 0.01;
		e->minxm += 0.01;
	}
	else if (key == K_RIGHT)
	{
		e->maxxm -= 0.01;
		e->minxm -= 0.01;
	}
	else if (key == K_DOWN)
	{
		e->maxy -= 0.01;
		e->miny -= 0.01;
	}
	else if (key == K_UP)
	{
		e->maxy += 0.01;
		e->miny += 0.01;
	}
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, LARGEUR, HAUTEUR);
	expose(e);
	e->x = 0;
	e->y = 0;

	return (0);
}

t_coord	super_hub(t_coord *e)
{
	if (strcmp(e->argv[1], "julia") == 0)
		ft_fractale2(*e);
	else if (strcmp(e->argv[1], "mandelbrot") == 0)
		ft_fractale(*e);
	else
		exit(0);
	return(*e);
}

int		expose(t_coord *e)
{
	*e = super_hub(e);
	return (0);
}
