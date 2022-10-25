/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:45:13 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/22 10:39:16 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	lsrc = ft_strlen(src);
	if (!dstsize)
		return (lsrc);
	ldst = ft_strlen(dst);
	if (ldst >= dstsize)
		return (dstsize + lsrc);
	i = 0;
	while (src[i] && i < dstsize - ldst - 1)
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	return (ldst + lsrc);
}
