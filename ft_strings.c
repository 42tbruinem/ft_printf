/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:22:54 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/01 21:36:34 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putnstr(const char *str, t_data data, int len)
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
	while (i <= len)
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

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
	if (nb == 0)
		str[0] = '0';
	while (n > 0 && size >= 0)
	{
		str[size] = (n % base) + get_addchar(data.type, n % base);
		n = n / base;
		size--;
	}
	return (str);
}

char	*ft_itoa(t_data data, int nb)
{
	int		base_size;
	int		size;
	char	*str;

	base_size = get_size(nb, get_base(data.type), data);
	size = base_size;
//	print_data(data);
	if (data.precision == 1 && data.max_width > base_size)
		size = data.max_width;
	if (data.precision == 1 && data.max_width >= base_size && nb < 0)
		size++;
//	printf("%d\n", size);
	str = malloc(size + 1);
	str = assign_numbers(data, nb, size - 1, str);
	return (str);
}

char	*ft_ultoa(t_data data, unsigned long nb)
{
	int		base_size;
	int		size;
	char	*str;

//	print_data(data);
	base_size = get_size(nb, get_base(data.type), data);
	size = base_size;
	if (data.precision == 1 && data.max_width > base_size)
		size = data.max_width;
	str = malloc(size + 1);
	str = assign_numbers(data, nb, size - 1, str);
	return (str);
}

void	ft_output(char *str, t_data data, int *count)
{
	int i;
	int len;

	i = 0;
//	print_data(data);
	len = (int)ft_strlen(str);
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
//	print_data(data);
//	printf("\ntype: %c, %d\n", data.type, len);
	*count += ft_putstr(str, data);
	if (data.direction == 1)
		while (i < data.min_width - len)
		{
			*count += ft_putchar(data.padding);
			i++;
		}
	free(str);
}
