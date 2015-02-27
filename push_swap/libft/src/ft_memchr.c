/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:41:27 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:14 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		if ((str[i]) == (unsigned char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
