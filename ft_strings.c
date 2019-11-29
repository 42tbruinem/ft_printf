/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:22:54 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/29 14:37:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putstr(const char *str)
{
	int		count;
	int		i;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	if (str[i] == 0)
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
	if (type == 'd' || type == 'i')
		return (10);
	else if (type == 'x' || type == 'X')
		return (16);
	else
		return (-1);
}

char	get_addchar(char type, int number)
{
	if (number >= 10 && number <= 16)
	{
		if (type == 'x')
			return ('a' - 10);
		if (type == 'X')
			return ('A' - 10);
	}
	return ('0');
}

int		get_size(long long nb, int base)
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
	return (size);
}

char	*assign_words(t_data data, long long nb, int size, char *str)
{
	unsigned long long	n;
	int					base;
	int					width;

	base = get_base(data.type);
	n = nb;
	str[size + 1] = 0;
	if (nb < 0)
	{
		str[0] = '-';
		n = nb * -1;
	}
	while (n > 0)
	{
		str[size] = (n % base) + get_addchar(data.type, n % base);
		n = n / base;
		size--;
	}
	return (str);
}

char	*ft_itoa(t_data data, long long nb)
{
	int		size;
	char	*str;

	size = get_size(nb, get_base(data.type));
	if (data.precision == 1 && data.max_width != 0)
		str = malloc(data.max_width + 1);
	else
		str = malloc(size + 1);
	str = assign_words(data, nb, size - 1, str);
	return (str);
}

int		ft_output(char *str, t_data data)
{
	return (1);
}

/* int		main(void)
{
	int n = 50;
	t_data data;

	data.type = 'X';
	data.precision = 0;
	data.direction = 0;
	data.max_width = 5;
	data.min_width = 0;
	data.padding = ' ';

	printf("%s\n", ft_itoa(data, -16));
	printf("%X\n", -16);
	return (0);
} */
