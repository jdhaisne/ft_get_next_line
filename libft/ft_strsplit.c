/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:10:23 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/04 12:32:08 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_word(char const *s, char c)
{
	int i;
	int j;
	int nb_word;

	i = 0;
	j = 0;
	nb_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && j == 0)
		{
			nb_word++;
			j = 1;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (nb_word);
}

static char		*get_word(int *j, char const *s, char c)
{
	char	*word;
	int		word_size;
	int		i;

	word = NULL;
	word_size = *j;
	i = 0;
	while (s[word_size] != c && s[word_size] != '\0')
		word_size++;
	if ((word = (char *)malloc(sizeof(char) * (word_size - *j) + 1)) == NULL)
		return (NULL);
	while (*j < word_size)
	{
		word[i] = s[*j];
		i++;
		*j = *j + 1;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		o;
	int		*j;

	tab = NULL;
	i = 0;
	o = 0;
	j = &o;
	if (s == NULL)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * count_word(s, c) + 1)) == NULL)
		return (NULL);
	while (i < count_word(s, c))
	{
		while (s[*j] == c)
			*j = *j + 1;
		if (s[*j] != c && s[*j] != '\0')
		{
			tab[i] = get_word(j, s, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
