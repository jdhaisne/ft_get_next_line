/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:05:33 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/01/12 13:03:44 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*snew;
	size_t	i;

	snew = NULL;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if ((snew = (char *)malloc((sizeof(char) * (s1len + s2len)) + 1)) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		snew[i] = s1[i];
		i++;
	}
	while (s2[i - s1len] != '\0')
	{
		snew[i] = s2[i - s1len];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
