/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:14:14 by dduval            #+#    #+#             */
/*   Updated: 2015/02/16 17:17:59 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

t_stack	*ft_rotate_list(t_stack **lst)
{
	t_stack *prevtmp;
	t_stack *tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	prevtmp = tmp;
	tmp = tmp->next;
	tmp->next = *lst;
	prevtmp->next = NULL;
	return (tmp);
}
