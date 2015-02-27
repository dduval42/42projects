/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:51:54 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 19:24:06 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		key_hook(int key, t_event *e)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	ft_move_up_down(key, e);
	ft_move_left_right(key, e);
	ft_config_move_speed(key, e);
	ft_config_rotate_speed(key, e);
	return (0);
}

int		loop(t_event *e)
{
	if (e->s->levels % 2 == 0)
		ft_levels(e);
	else
		ft_ray_cast(e);
	ft_end_levels(e);
	ft_tp(e);
	return (0);
}

void	ft_loop(void)
{
	t_event *e;

	e = ft_init_struct();
	e->m->mlx = mlx_init();
	e->m->win = mlx_new_window(e->m->mlx, LARGEUR, HAUTEUR, "wolf");
	mlx_hook(e->m->win, 2, 3, key_hook, e);
	mlx_loop_hook(e->m->mlx, loop, e);
	mlx_loop(e->m->mlx);
	mlx_destroy_image(e->m->mlx, e->m->img);
	mlx_destroy_window(e->m->mlx, e->m->win);
}
