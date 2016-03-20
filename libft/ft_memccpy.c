/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:51:14 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 13:16:53 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (((char *)src)[i] != (char)c && i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	if (((char *)src)[i] == (char)c)
	{
		((char *)dest)[i] = ((char *)src)[i];
		return (dest + (i + 1));
	}
	return (NULL);
}
