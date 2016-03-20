/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:21:36 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 15:55:56 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*snew;

	i = 0;
	snew = NULL;
	if (s == NULL)
		return (NULL);
	snew = (char *)malloc((sizeof(char) * len) + 1);
	if (snew == NULL)
		return (NULL);
	while (i < len)
	{
		snew[i] = s[i + start];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
