/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:39:06 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 13:19:45 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*snew;

	size = 0;
	i = 0;
	snew = NULL;
	if (s == NULL && f == NULL)
		return (NULL);
	size = ft_strlen(s);
	snew = (char*)malloc((sizeof(char) * size) + 1);
	if (snew == NULL)
		return (NULL);
	while (i < size)
	{
		snew[i] = (*f)(s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
