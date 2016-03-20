/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:41:55 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/02 16:00:33 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' \
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
	{
		i++;
		j++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[j] == '-')
		ret = ret * -1;
	if (nptr[j] == '+')
		ret = ret * 1;
	return (ret);
}
