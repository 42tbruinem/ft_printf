/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 18:25:10 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/02 18:26:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	zero_pad(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
}

char	get_addchar(char type, int number)
{
	if (number >= 10 && number <= 16)
	{
		if (type == 'x' || type == 'p')
			return ('a' - 10);
		if (type == 'X')
			return ('A' - 10);
	}
	return ('0');
}

int		get_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return (10);
	if (type == 'o')
		return (8);
	else if ((type == 'x' || type == 'X') || type == 'p')
		return (16);
	else
		return (-1);
}

int		get_size(long long nb, int base, t_data data)
{
	int					size;
	unsigned long long	n;

	size = 0;
	if (nb <= 0)
	{
		n = nb * -1;
		size++;
	}
	else
		n = nb;
	while (n > 0)
	{
		size++;
		n /= base;
	}
	if (data.padding == '0' && data.min_width > size)
		return (data.min_width);
	return (size);
}

char	*assign_numbers(t_data data, long long nb, int size, char *str)
{
	unsigned long long	n;
	int					base;

	base = get_base(data.type);
	n = nb;
	zero_pad(str, size);
	str[size + 1] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		n = nb * -1;
	}
	if (nb == 0 && data.precision == 0 && data.max_width >= 0)
		str[0] = '0';
	while (n > 0 && size >= 0)
	{
		str[size] = (n % base) + get_addchar(data.type, n % base);
		n = n / base;
		size--;
	}
	return (str);
}
