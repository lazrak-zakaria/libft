/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:05:24 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/20 20:35:27 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;
	char	*a;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	l = ft_strlen(s1) - 1;
	while (search(set, s1[i]))
		i++;
	while (search(set, s1[l]) && l >= i)
		l--;
	if (l < i)
	{
		a = (char *)malloc(sizeof(char));
		if (!a)
			return (NULL);
		*a = '\0';
		return (a);
	}
	a = ft_substr(s1, i, l - i + 1);
	return (a);
}
