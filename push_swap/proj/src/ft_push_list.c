/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:14:18 by dduval            #+#    #+#             */
/*   Updated: 2015/02/16 17:16:03 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

void	ft_push_list(t_stack **lsta, t_stack **lstb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpb = *lstb;
	tmpa = *lsta;
	*lsta = (*lsta)->next;
	tmpa->next = tmpb;
	*lstb = tmpa;
}
