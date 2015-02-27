/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:41:11 by dduval            #+#    #+#             */
/*   Updated: 2015/02/12 10:42:58 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_stop_str(char *str, char c)
{
	int		i;
	char	*ret;
	int		len;

	i = 0;
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, c));
	ret = (char *)malloc(len + 1);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
