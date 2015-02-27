/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:38:07 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:28:06 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_free_join(char *s1, char *s2, int fre)
{
	if (fre == FIRST)
		free(s1);
	else if (fre == SEC)
		free(s2);
	else if (fre == BOTH)
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strjoin(char const *s1, char const *s2, int fre)
{
	char	*dest;
	int		i;
	int		j;

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
	if (fre < 4)
		ft_free_join((char *)s1, (char *)s2, fre);
	return (dest);
}
