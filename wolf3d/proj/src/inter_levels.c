/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_levels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:51:45 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:22:35 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_inter_levels(t_event *e)
{
	char	*tmp;
	int		min;
	int		mtime;

	mtime = e->wintime;
	if (e->s->levels != 8)
		tmp = ft_strdup("Welcome to a new level");
	else
	{
		mtime = time(NULL) - mtime - 4;
		min = ft_get_minute(&(mtime));
		tmp = ft_strjoin("Tu as gagne en ",
			ft_strjoin(ft_itoa(min), ft_strjoin(" mn et ",
				ft_strjoin(ft_itoa(mtime), " sec", FIRST), SEC), BOTH), SEC);
	}
	e->m->img = mlx_new_image(e->m->mlx, LARGEUR, HAUTEUR);
	mlx_string_put(e->m->mlx, e->m->win, LARGEUR / 2, HAUTEUR / 2, RED, tmp);
	free(tmp);
	mlx_put_image_to_window(e->m->mlx, e->m->win, e->m->img, 0, 0);
	sleep(1);
	mlx_destroy_image(e->m->mlx, e->m->img);
}
