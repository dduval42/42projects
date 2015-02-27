/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:38:07 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:47 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (s1 && s2)
	{
		j = 0;
		i = 0;
		if (!(dest = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			dest[i] = s2[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
