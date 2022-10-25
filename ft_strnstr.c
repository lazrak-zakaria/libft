/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:18:03 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/13 17:26:55 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		k = 0;
		while ((haystack[i + k] == needle[k]) && (needle[k]) && (k + i) < len)
			k++;
		if (!needle[k])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
