/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:00:52 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:42 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	char			*dest;
	int				lenght;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		lenght = ft_strlen (s);
		dest = ft_strnew (lenght);
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
