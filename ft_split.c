/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:18:17 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/20 09:08:02 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_words(const char *s, char c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i])
		{
			a++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (a);
}

static char	**mem_free(char **a)
{
	size_t	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
	return (NULL);
}

static char	**split_str(const char *s, char **a, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] == c)
			while (s[i] == c && s[i])
				i++;
		else if (s[i] && s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			a[k] = ft_substr(s, j, (i - j));
			if (!a[k++])
				return (mem_free(a));
		}
	}
	a[k] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**a;

	if (!s)
		return (NULL);
	w = c_words(s, c);
	a = (char **)malloc(sizeof(char *) * (w + 1));
	if (!a)
		return (NULL);
	a = split_str(s, a, c);
	return (a);
}
