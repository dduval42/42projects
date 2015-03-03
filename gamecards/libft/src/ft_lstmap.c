/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 12:02:45 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:23 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *dest;
	t_list *tmp;
	t_list *tmp2;

	tmp = lst;
	if (!(dest = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst && f)
	{
		dest = f(lst);
		tmp2 = dest;
		while (lst->next != NULL)
		{
			lst = lst->next;
			dest->next = f(lst);
			dest = dest->next;
		}
	}
	dest = tmp2;
	lst = tmp;
	return (dest);
}
