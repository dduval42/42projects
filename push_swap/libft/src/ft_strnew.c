/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:14:00 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:38 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char *)malloc(size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
