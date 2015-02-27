/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:14:39 by dduval            #+#    #+#             */
/*   Updated: 2015/02/16 17:18:02 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

t_stack	*ft_reverse_rotate_list(t_stack **lst)
{
	t_stack *prevtmp;
	t_stack *tmp;
	t_stack	*ret;

	ret = *lst;
	ret = ret->next;
	prevtmp = *lst;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = prevtmp;
	prevtmp->next = NULL;
	return (ret);
}
