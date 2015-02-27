/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:09:49 by dduval            #+#    #+#             */
/*   Updated: 2015/02/19 17:55:13 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

t_lstsh		*ft_fill_list(char **arg)
{
	int i;
	t_lstsh	*lst;
	t_lstsh *new;
	t_lstsh *tmp;

	lst = (t_lstsh *)malloc(sizeof(t_lstsh));
	i = 1;
	lst->content = arg[0];
	tmp = lst;
	while (arg[i])
	{
		new = (t_lstsh *)malloc(sizeof(t_lstsh));
		new->content = arg[i];
		lst->next = new;
		new->prev = lst;
		new->next = NULL;
		lst = lst->next;
		i++;
	}
	return (tmp);
}

int		main(int argc, char **argv)
{
	ft_aff_list(ft_fill_list(ft_parse(ft_strdup(argv[1]), ";><")));
	return ;
}
