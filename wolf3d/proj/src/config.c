/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:19:16 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:39:58 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_config_move_speed(int key, t_event *e)
{
	if (key == PLUS && e->c->ms < 1)
		e->c->ms += 0.05;
	if (key == MINUS && e->c->ms >= 0.05)
		e->c->ms -= 0.05;
}

void	ft_config_rotate_speed(int key, t_event *e)
{
	if (key == ONE && e->c->rs < 1)
		e->c->rs += 0.025;
	if (key == ZERO && e->c->rs >= 0.025)
		e->c->rs -= 0.025;
}
