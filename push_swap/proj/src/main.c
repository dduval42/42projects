/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:10:10 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 17:54:26 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push.h>

void	ft_new_order(t_stack *lst, t_stack *lstb, int mediane, int mini)
{
	t_stack *tmp;
	int		len;
	int		i;
	int		toto;

	len  = ft_stacksize(lst);
	i = 0;
	toto = ft_bol_mini(lst, len, mini);
	while(lst->content != mini)
	{
		if (toto == 1)
			lst = ft_rotate_list(&lst);
		else
			lst = ft_reverse_rotate_list(&lst);
		ft_putstr(" ra");
	}
	while (i < len)
	{
		if (lst->content == ft_mini(lst))
		{
			ft_push_list(&lst, &lstb);
			ft_putstr(" pb");
			i++;
		}
		else
		{
			if (lst->next->content == mini)
				ft_swap_list(&lst);
			else if (toto == 1)
				lst = ft_rotate_list(&lst);
			else
				lst = ft_reverse_rotate_list(&lst);
			ft_putstr(" ra");
			toto++;
		}
	}
	while (lstb)
	{
		ft_push_list(&lstb, &lst);
		ft_putstr(" pa");
		i--;
	}
}

int		main(int argc, char **argv)
{
	t_stack *lst;
	t_stack *lstb;

	lstb = NULL;
	if (argc != 1)
	{
		lst = ft_fill_list(argv);
		ft_new_order(lst, lstb, ft_mediane(&lst), ft_mini(lst));
	//	ft_my_order(lst, lstb, ft_mediane(&lst));
		ft_putchar('\n');
	}
//	ft_aff_list(lst);
//	ft_aff_list(lstb);
}
