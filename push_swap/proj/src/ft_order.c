/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:00:36 by dduval            #+#    #+#             */
/*   Updated: 2015/02/19 12:57:45 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

int		ft_order(t_stack *lst)
{
	t_stack *tmp;
	int		i;

	i = 1;
	while (lst->next)
	{
		tmp =  lst->next;
		if (tmp->content < lst->content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (0);
}
