/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:31:41 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:31 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strsub(const char *s1, unsigned int start, size_t len)
{
	size_t	j;
	char	*dest;

	if ((int)len < 0)
		return (NULL);
	if (s1)
	{
		j = 0;
		dest = ft_strnew(len + 1);
		while (j < len)
		{
			dest[j] = s1[start];
			start++;
			j++;
		}
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}
