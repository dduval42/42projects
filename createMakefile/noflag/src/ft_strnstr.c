/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:47:17 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:37 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			k++;
			i = k;
			j = 0;
		}
	}
	if (s2[j] != '\0')
		return (NULL);
	return ((char *)(s1 + i - j));
}
