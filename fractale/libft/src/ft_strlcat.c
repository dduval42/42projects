/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:45:12 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:46 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	size;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	size = n;
	while (*dest && n)
	{
		dest++;
		n--;
	}
	if (!n)
		return (size + len_src);
	while (*src && n-- > 1)
		*dest++ = *src++;
	*dest = '\0';
	return (len_dest + len_src);
}
