/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 16:53:55 by dduval            #+#    #+#             */
/*   Updated: 2015/02/13 12:14:37 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract.h>

int		ft_pow(int i, int pow)
{
	int p;

	p = i;
	while (pow > 0)
	{
		p *= i;
		pow--;
	}
	return(p);

}

t_coord		ft_zoom(t_coord e)
{
	static int i;
	if (e.h > 0.5)
		e.iter = 50;
	else if (e.h > 0.1)
		e.iter = 150;
	else if (e.h > 0.01)
		e.iter = 300;
	else if (e.h > 0.001)
		e.iter = 400;
	else if (e.h > 0.0001)
		e.iter = 800;
	else if (e.h > 0.00001)
		e.iter = 1600;
	else if (e.h > 0.000001)
		e.iter = 2400;
	else if (e.h > 0.0000001)
		e.iter = 3200;
	else
		e.iter *= 2;
	i++;
	printf("e.h = %f, e.iter = %d, nb zoom = %d\n", e.h, e.iter, ft_pow(2, i));
	return (e);
}
