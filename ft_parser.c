/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:45:26 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/19 16:26:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		match(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_data	get_flags(t_data data, const char *str, va_list list)
{
	if (*str == '-')
	{
		data.direction = 1;
		data.padding = ' ';
	}
	if (*str == '0' && data.direction == 0)
		data.padding = '0';
	if (*str == '.')
		data.precision = 1;
	if (data.precision == 1 && (*str >= '0' && *str <= '9'))
		data.max_width = ft_atoi(str);
	if (data.precision == 0 && (*str >= '0' && *str <= '9'))
		data.min_width = ft_atoi(str);
	if (data.precision == 0 && *str == '*')
		data.min_width = va_arg(list, int);
	if (data.precision == 1 && *str == '*')
		data.max_width = va_arg(list, int);
	return (data);
}

t_data	get_data(const char *str, va_list list)
{
	t_data		data;

	data.min_width = 0;
	data.max_width = 0;
	data.type = 0;
	data.direction = 0;
	data.padding = 0;
	data.precision = 0;
	if (*str == '%')
		data.type = '%';
	while (*str != 0 && *str != '%')
	{
		if (match(*str, VALID_TYPE))
		{
			data.type = *str;
			return (data);
		}
		else if (match(*str, VALID_FLAG))
			data = get_flags(data, str, list);
		str++;
	}
	return (data);
}

int		compatibility_check(t_data data)
{
	return (1);
}

int		make_string(t_data data, va_list list)
{
	const char	*str;
	int			count;

	str = NULL;
	count = 0;
	if (data.type == 'd' || data.type == 'i' || data.type == 'u')
		str = ft_itoa(data, va_arg(list, int));
	if (data.type == 's')
		str = ft_strdup(va_arg(list, char *));
	if (data.type == 'X' || data.type == 'x')
		str = ft_itoa(data, va_arg(list, int));
	count = ft_putstr(str);
	return (count);
}
