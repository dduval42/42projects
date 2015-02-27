/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 17:21:32 by dduval            #+#    #+#             */
/*   Updated: 2015/02/19 18:18:18 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_strlen_cust(char *str, char *sp)
{
	int i;

	i = 0;
	while (str[i] && ft_check(str[i], sp) == 0)
		i++;
	return (i);
}

char	*ft_fill_spe(char **str)
{
	char *ret;
		ret = (char *)malloc(3);
		ret[0] = **str;
		if ((str[0][1] == '>' && str[0][0] == '>')
			|| (str[0][1] == '<' && str[0][0] == '<'))
		{
			ret[1] = **str;
			ret[2] = '\0';
			*str += 2;
		}
		else
		{
			(*str)++;
			ret[1] = '\0';
		}
		return (ret);
}

char	**ft_parse(char *str, char *sp)
{
	int		ct;
	int		tot;
	int		i;
	char	**ret;

	i = 0;
	tot = ft_count_word(str, sp);
	ret = (char **)malloc(sizeof(char *) * (tot + 1));
	while (*str)
	{
		ct = ft_strlen_cust(str, sp);
		ret[i] = (char *)malloc(sizeof(char) * ct + 1);
		ret[i] = memcpy(ret[i], str, ct);
		ret[i][ct] = '\0';
		str += ct;
		if (ct != 0)
			i++;
		ret[i] = ft_fill_spe(&str);
		i++;
	}
	ret[tot] = NULL;
	return (ret);
}
