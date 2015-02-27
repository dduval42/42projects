/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:57:31 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:43 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		lenght;
	int		i;
	char	*dest;

	if (s && f)
	{
		lenght = ft_strlen(s);
		dest = ft_strnew (lenght);
		i = 0;
		while (s[i])
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
