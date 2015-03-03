/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:16:26 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:25 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del && *alst)
	{
		while ((*alst)->next != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
