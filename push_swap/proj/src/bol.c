/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:39:46 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 17:47:47 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

int		ft_bol_mini(t_stack *lst, int len, int mini)
{
	int i;

	i = 0;
	while(lst && lst->content != mini)
	{
		i++;
		lst = lst->next;
	}
	if (i < len / 2)
		return (1);
	else
		return (0);
}
