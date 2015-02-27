/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:18:31 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 19:06:06 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_levels(t_event *e)
{
	if (e->s->levels == 0)
		e->s->argv = ft_strdup("./map/level1.map");
	else if (e->s->levels == 2)
		e->s->argv = ft_strdup("./map/level2.map");
	else if (e->s->levels == 4)
		e->s->argv = ft_strdup("./map/level3.map");
	else if (e->s->levels == 6)
		e->s->argv = ft_strdup("./map/level4.map");
	e->s->map = ft_recup_map(e);
	ft_init_pos(e);
	e->s->tp = ft_init_tp(e);
	ft_inter_levels(e);
	e->s->levels++;
}
