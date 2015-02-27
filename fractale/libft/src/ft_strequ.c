/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:22:49 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:51 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(const char *s1, const char *s2)
{
	int i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		if (s1[i] == s2[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
