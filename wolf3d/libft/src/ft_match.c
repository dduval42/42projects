/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:47:27 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:18 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_match(char *s1, char *s2)
{
	if (!*s2 && !*s1)
		return (1);
	else if (!*s1)
	{
		if (*s2 == '*' && ft_match(s1, s2 + 1))
			return (1);
	}
	else if (*s2 == '*')
	{
		if (ft_match(s1, s2 + 1) || ft_match(s1 + 1, s2))
			return (1);
	}
	else if (*s1 == *s2 && ft_match(s1 + 1, s2 + 1))
		return (1);
	return (0);
}
