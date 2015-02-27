/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 19:19:39 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 20:06:48 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_free_int(int **tp)
{
	int i;

	i = 0;
	while (tp[i])
	{
		free(tp[i]);
		i++;
	}
	free(tp);
}

void	ft_end_levels(t_event *e)
{
	if (e->s->map[(int)e->c->posx][(int)e->c->posy] == '.')
	{
		e->s->levels += 1;
		if (e->s->tp)
			ft_free_int(e->s->tp);
		free(e->s->argv);
		ft_free_tab(e->s->map);
		if (e->s->levels == 8)
		{
			ft_inter_levels(e);
			exit (EXIT_SUCCESS);
		}
	}
}
