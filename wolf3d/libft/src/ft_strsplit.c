/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:48:50 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:28:46 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strtrimcarac(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = ft_strlen(s);
	j = 0;
	k = 0;
	dest = (char *)malloc(i + 2);
	while (s[j] == c)
		j++;
	i--;
	while (s[i] == c)
		i--;
	while (j <= i)
		dest[k++] = s[j++];
	dest[k] = '\0';
	return (dest);
}

static int	ft_count_word(char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			k++;
		i++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	char	*new;
	int		i;
	int		len;
	int		j;

	if (!s || !c)
		return (NULL);
	j = 0;
	i = 0;
	new = ft_strtrimcarac ((char *)s, c);
	len = ft_count_word(new, c);
	dest = (char **)malloc(sizeof(char *) * (len + 1) + 1);
	while (*new != '\0' && i < len)
	{
		dest[i] = malloc(ft_strlencarac(new, c) + 1);
		while (*new != c && *new != '\0')
			dest[i][j++] = *(new++);
		dest[i++][j] = '\0';
		while (*new == c)
			new++;
		j = 0;
	}
	dest[i] = NULL;
	return (dest);
}
