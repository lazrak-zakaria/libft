/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:51:55 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/20 15:22:56 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	b;

	if (!count || !size)
		return (malloc(0));
	b = count * size;
	if (count == (b / size))
	{
		a = malloc(b);
		if (!a)
			return (NULL);
		ft_memset(a, 0, b);
		return (a);
	}
	return (NULL);
}
