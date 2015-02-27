/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:10:25 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 17:46:53 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <libft.h>
# include <stdio.h>

typedef		struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void		ft_aff_list(t_stack *lst);
t_stack		*ft_rotate_list(t_stack **lst);
void		ft_push_list(t_stack **lsta, t_stack **lstb);
t_stack		*ft_fill_list(char **argv);
void		ft_swap_list(t_stack **lst);
int			ft_stacksize(t_stack *lst);
t_stack		*ft_reverse_rotate_list(t_stack **lst);
int			ft_order(t_stack *lst);
int			ft_mediane(t_stack **lst);
int			ft_mini(t_stack *lst);
int		ft_bol_mini(t_stack *lst, int len, int mini);
#endif
