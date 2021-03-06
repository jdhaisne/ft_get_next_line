/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:39:13 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 13:45:11 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t size;
	size_t i;

	size = 0;
	i = 0;
	if (s == NULL)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
}
