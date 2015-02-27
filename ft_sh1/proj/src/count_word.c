/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 17:28:48 by dduval            #+#    #+#             */
/*   Updated: 2015/02/19 17:34:54 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

int		ft_check(char c, char *sp)
{
	int		i;

	i = 0;
	while (sp[i])
	{
		if (sp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_word(char *s, char *sp)
{
	int		ct;
	int		i;

	i = 0;
	ct = 0;
	while (s[i])
	{
		if (s[i] != ' ' && ft_check(s[i], sp) == 0 && (s[i + 1] == ' '
			|| s[i + 1] == '\0' || ft_check(s[i + 1], sp) == 1))
				ct++;
		else if (ft_check(s[i], sp) == 1)
		{
			ct++;
			if (s[i] == s[i + 1])
				i++;
		}
		i++;
	}
	return (ct);
}
