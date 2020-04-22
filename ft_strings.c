/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:22:54 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/16 12:52:57 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putstr(const char *str, t_data data)
{
	int		count;
	int		i;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	if (str[i] == 0 && data.type == 'c')
	{
		write(1, &str[i], 1);
		count++;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

char	*ft_itoa(t_data data, int nb)
{
	int		base_size;
	int		size;
	char	*str;

	base_size = get_size(nb, get_base(data.type), data);
	size = base_size;
	if (data.precision == 1 && data.max_width >= base_size)
		size = data.max_width;
	if (data.precision == 1 && data.max_width >= base_size && nb <= 0)
		size++;
	str = ft_calloc(size + 1);
	if (str == NULL)
		return (NULL);
	str = assign_numbers(data, nb, size - 1, str);
	return (str);
}

char	*ft_ultoa(t_data data, unsigned long nb)
{
	int		base_size;
	int		size;
	char	*str;

	base_size = get_size(nb, get_base(data.type), data);
	if (data.type == 'p')
		base_size = get_ulsize(nb, get_base(data.type), data);
	size = base_size;
	if (data.precision == 1 && data.max_width >= base_size)
		size = data.max_width;
	if (data.precision == 1 && data.max_width >= base_size && nb == 0)
		size++;
	str = ft_calloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (data.type == 'p')
		str = assign_ulnumbers(data, nb, size - 1, str);
	else
		str = assign_numbers(data, nb, size - 1, str);
	str[size] = 0;
	return (str);
}

char	*ft_convert_c(t_data data, va_list list)
{
	char *str;

	str = (char *)ft_calloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = data.type;
	if (data.type == 'c')
		str[0] = va_arg(list, int);
	str[1] = 0;
	return (str);
}

void	ft_output(char *str, t_data data, int *count)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(str, data);
	if (data.type == 'p')
		len += 2;
	if (data.direction == 0)
		while (i < data.min_width - len)
		{
			*count += ft_putchar(data.padding);
			i++;
		}
	if (data.type == 'p')
		*count += ft_putstr("0x", data);
	*count += ft_putstr(str, data);
	if (data.direction == 1)
		while (i < data.min_width - len)
		{
			*count += ft_putchar(data.padding);
			i++;
		}
	free(str);
}
