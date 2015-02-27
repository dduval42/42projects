/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_intab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:27:09 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 14:27:51 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_remove_intab(char **tab, char *str)
{
	int		i;
	int		len;
	char	**ret;
	int		j;

	len = ft_lentab(tab);
	ret = (char **)malloc(sizeof(char *) * (len - 1) + 1);
	i = 0;
	j = 0;
	len = ft_strlen(str) - 1;
	while (tab[i])
	{
		if (ft_match(ft_stop_str(tab[i], '='), str) == 0)
		{
			ret[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	ret[j] = NULL;
	ft_free_tab(tab);
	return (ret);
}
