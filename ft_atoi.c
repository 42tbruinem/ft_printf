/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:24:56 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/19 14:49:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(const char *str)
{
	int					n;
	unsigned long long	res;

	n = 1;
	res = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			n = n * -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (res > 9223372036854775807)
		{
			if (n == -1)
				return (0);
			return (-1);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * n);
}
