/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:07:28 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:17 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = malloc (size)) || size == 0)
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
