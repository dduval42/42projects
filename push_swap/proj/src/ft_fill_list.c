/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:18:00 by dduval            #+#    #+#             */
/*   Updated: 2015/02/16 16:02:04 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

t_stack	*ft_fill_list(char **argv)
{
	t_stack	*lst;
	t_stack	*new;
	t_stack *tmp;
	int		i;

	i = 2;
	lst = (t_stack *)malloc(sizeof(t_stack));
	lst->content = ft_atoi(argv[1]);
	lst->next = NULL;
	tmp = lst;
	while (argv[i])
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		new->content = ft_atoi(argv[i]);
		new->next = NULL;
		tmp->next = new;
		tmp = tmp->next;
		i++;
	}
	return (lst);
}
