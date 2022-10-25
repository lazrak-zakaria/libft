/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:30:58 by zlazrak           #+#    #+#             */
/*   Updated: 2022/10/20 09:07:18 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\r' || c == '\n'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	a;
	long long	p;
	int			i;
	int			s;

	i = 0;
	a = 0;
	s = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		s = ((str[i] == '+') - (str[i] == '-'));
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		p = a;
		a = (a * 10) + (s * (str[i++] - '0'));
		if (s == 1 && a < p)
			return (-1);
		else if (s == -1 && a > p)
			return (0);
	}
	return (a);
}
