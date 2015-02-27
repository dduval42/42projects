/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 18:55:18 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 20:08:20 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		ft_tab_int(int **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int		**ft_realloc_int_tab(int **tp, int *tmp)
{
	int	**ret;
	int	i;
	int len;

	len = (ft_tab_int(tp) + 1) * 8;
	i = 0;
	ret = (int **)malloc(len + 1);
	while (tp && tp[i])
	{
		ret[i] = tp[i];
		i++;
	}
	free (tp);
	ret[i] = tmp;
	i++;
	ret[i] = NULL;
	return (ret);
}

int		*ft_fill_tp(int x, int y)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * 3);
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = -1;
	return (tmp);
}

int		**ft_init_tp(t_event *e)
{
	int	**tp;
	int	x;
	int	y;

	x = 0;
	tp = NULL;
	while (e->s->map[x])
	{
		y = 0;
		while (e->s->map[x][y])
		{
			if (e->s->map[x][y] == '!')
				tp = ft_realloc_int_tab(tp, ft_fill_tp(x, y));
			y++;
		}
		x++;
	}
	return (tp);
}
