/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:56:45 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:10 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	char		*tmp;
	size_t		i;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	tmp = ft_strnew(ft_strlen(source));
	ft_strcpy(tmp, source);
	while (i < len)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
