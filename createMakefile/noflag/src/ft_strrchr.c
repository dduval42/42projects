/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:57:08 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:35 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int j;
	int bol;

	bol = 0;
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			bol = 1;
			j = i;
		}
		i++;
	}
	if ((char)c == 0)
		return ((char *)(str + i));
	if (bol == 0)
		return (NULL);
	return ((char *)(str + j));
}
