/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:46:42 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/20 10:44:51 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (a == b)
		return (dst);
	if (a > b)
	{
		while (i < len)
		{
			a[len - i - 1] = b[len - i - 1];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
