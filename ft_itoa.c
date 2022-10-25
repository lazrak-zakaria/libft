/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:03:27 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/13 17:16:09 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

static int	int_len(int n)
{
	int	l;

	l = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		l;
	int		i;
	char	*a;

	l = int_len(n);
	if (n < 0)
		l++;
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	i = 0;
	if (n < 0)
		a[i++] = '-';
	a[l--] = '\0';
	while (l >= i)
	{
		a[l--] = _abs(n % 10) + '0';
		n /= 10;
	}
	return (a);
}
