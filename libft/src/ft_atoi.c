/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:29:44 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:29 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int bol;

	i = 0;
	nb = 0;
	bol = -1;
	while (str[i] == ' ' || str[i] == 13 || str[i] == 9 || str[i] == 12
			|| str[i] == '\v' || str[i] == 10)
		i++;
	if (str[i] == '-')
	{
		bol = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		if (((nb = nb * 10 - str[i] + '0') > 0))
			return ((bol == 1) ? 0 : -1);
		i++;
	}
	return (nb * bol);
}
