/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:12:50 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:30 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strtrim(char const *s)
{
	int			i[2];
	char		*dest;
	int			k;

	k = 0;
	i[0] = 0;
	i[1] = 0;
	if (s)
	{
		while (s[i[1]] != '\0')
			i[1]++;
		dest = ft_strnew(i[0]);
		while ((s[i[0]] == ' ' || s[i[0]] == 10 || s[i[0]] == 9) && s[i[0]])
			i[0]++;
		i[1]--;
		while ((s[i[1]] == ' ' || s[i[1]] == 10 || s[i[1]] == 9) && i[1] > 0)
			i[1]--;
		while (i[0] <= i[1])
		{
			dest[k++] = s[i[0]++];
		}
		dest[k] = '\0';
		return (dest);
	}
	return (NULL);
}
