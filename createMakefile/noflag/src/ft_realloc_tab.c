/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 19:53:42 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:43:00 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_realloc_tab(char **tab, char *str)
{
	char	**dest;
	int		len;
	int		i;

	len = ft_lentab(tab);
	dest = (char **)malloc(sizeof(char *) * (len + 1) + 1);
	i = 0;
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	dest[i] = ft_strdup(str);
	dest[i + 1] = NULL;
	ft_free_tab(tab);
	return (dest);
}
