/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 12:01:26 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:08 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printtab_fd(char **tab, int fd)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		i++;
	}
}
