/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:14:06 by dduval            #+#    #+#             */
/*   Updated: 2015/02/16 16:00:33 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

void	ft_swap_list(t_stack **lst)
{
	int		tmp;

	if ((*lst)->next)
	{
		tmp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = tmp;
	}
}
