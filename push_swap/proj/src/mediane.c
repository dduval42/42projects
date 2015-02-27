/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:25:58 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 17:13:59 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

int		medianornot(int median, t_stack *lst)
{
	int cpt;
	int count;

	count = ft_stacksize(lst);
	cpt = 0;
	while (lst)
	{
		if (lst->content >= median)
			cpt++;
		lst = lst->next;
	}
	if (count % 2 != 0 && cpt == (count / 2 + 1))
		return (0);
	else if (cpt == (count / 2) + 1)
		return (0);
	else
		return (1);
}
int		ft_mediane(t_stack **lst)
{
	t_stack *tmp;
	int		med;

	tmp = *lst;
	while (tmp)
	{
		if (medianornot(tmp->content, *lst) == 0)
			return(tmp->content);
		tmp = tmp->next;
	}
}
