/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:44:31 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/16 11:59:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_ulsize(unsigned long n, int base, t_data data)
{
	int		size;

	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		size++;
		n /= base;
	}
	if (data.padding == '0' && data.min_width > size)
		return (data.min_width);
	return (size);
}

char	*assign_ulnumbers(t_data data, unsigned long n, int size, char *str)
{
	int					base;

	base = get_base(data.type);
	zero_pad(str, size);
	str[size + 1] = 0;
	if (n == 0 && data.precision == 0 && data.max_width >= 0)
		str[0] = '0';
	while (n > 0 && size >= 0)
	{
		str[size] = (n % base) + get_addchar(data.type, n % base);
		n = n / base;
		size--;
	}
	return (str);
}
