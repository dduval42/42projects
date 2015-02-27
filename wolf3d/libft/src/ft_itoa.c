/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:37:50 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 12:57:12 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*newstr(int n)
{
	int			lenght;
	char		*dest;
	int			i;

	i = 0;
	if (n <= 0)
		lenght = 1;
	else
		lenght = 0;
	while (n != 0)
	{
		lenght++;
		n /= 10;
	}
	dest = (char *)malloc(lenght + 1);
	while (i < lenght)
	{
		dest[i] = 'a';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*limit(char *src)
{
	src[0] = '-';
	src[1] = '2';
	src[2] = '1';
	src[3] = '4';
	src[4] = '7';
	src[5] = '4';
	src[6] = '8';
	src[7] = '3';
	src[8] = '6';
	src[9] = '4';
	src[10] = '8';
	src[11] = '\0';
	return (src);
}

char			*ft_itoa(int n)
{
	int			lenght;
	char		*dest;
	int			nb;

	nb = n;
	dest = newstr (n);
	lenght = ft_strlen (dest);
	if (nb < 0)
		nb *= -1;
	dest[lenght] = '\0';
	lenght--;
	while (lenght >= 0)
	{
		dest[lenght] = nb % 10 + 48;
		nb /= 10;
		lenght--;
	}
	if (n < 0)
		dest[0] = '-';
	if (n == -2147483648)
		dest = limit(dest);
	return (dest);
}
