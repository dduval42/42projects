/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:23 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 17:09:49 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

int		ft_mini(t_stack *lst)
{
	int mini;

	mini = lst->content;
	while(lst)
	{
		if (lst->content < mini)
			mini = lst->content;
		lst = lst->next;
	}
	return (mini);
}
