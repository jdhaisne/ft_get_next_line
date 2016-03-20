/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:14:25 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 13:59:17 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*snew;
	unsigned int	i;
	size_t			len;
	size_t			j;

	snew = NULL;
	i = 0;
	len = 0;
	j = 1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - j] == ' ' || s[len - j] == ',' || s[len - j] == '\n' || \
			s[len - j] == '\t')
		j++;
	if (s[i] == '\0')
		j = 0;
	else
		j--;
	snew = ft_strsub(s, i, len - j - i);
	if (snew == NULL)
		return (NULL);
	return (snew);
}
