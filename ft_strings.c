/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 18:22:54 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/02 19:01:11 by tbruinem      ########   odam.nl         */
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

char	*ft_calloc(int size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * size);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
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
	str = assign_numbers(data, nb, size - 1, str);
	return (str);
}

char	*ft_ultoa(t_data data, unsigned long nb)
{
	int		base_size;
	int		size;
	char	*str;

	base_size = get_size(nb, get_base(data.type), data);
	size = base_size;
	if (data.precision == 1 && data.max_width >= base_size)
		size = data.max_width;
	if (data.precision == 1 && data.max_width >= base_size && nb == 0)
		size++;
	str = ft_calloc(size + 1);
	str = assign_numbers(data, nb, size - 1, str);
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
