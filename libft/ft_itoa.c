/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:07:44 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 15:59:57 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		getnbsize(int n)
{
	int			size;
	int			i;

	size = 0;
	i = 1;
	while (n >= i)
	{
		i = i * 10;
		size++;
	}
	return (size);
}

static	char	*filltab(int n, int i, int j, char *buff)
{
	while (i > 0)
	{
		buff[j] = (n / i) % 10 + '0';
		j++;
		i = i / 10;
	}
	buff[j] = '\0';
	return (buff);
}

char			*ft_itoa(int n)
{
	int			i;
	int			j;
	char		*buff;

	i = 1;
	j = 0;
	buff = NULL;
	if (n == -2147483648)
	{
		buff = ft_strdup("-2147483648");
		return (buff);
	}
	buff = (char *)malloc(sizeof(char) * getnbsize(n));
	if (buff == NULL)
		return (NULL);
	if (n < 0)
	{
		buff[j] = '-';
		n = n * -1;
		j++;
	}
	while ((n / i) >= 10)
		i = i * 10;
	buff = filltab(n, i, j, buff);
	return (buff);
}
