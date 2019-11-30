/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:45:26 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/30 18:19:13 by tbruinem      ########   odam.nl         */
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

int		get_flags(t_data *data, const char *str, va_list list)
{
	int size;

	size = 1;
	if (*str == '-')
	{
		data->direction = 1;
		data->padding = ' ';
	}
	if (*str == '0' && data->direction == 0 && data->precision == 0)
		data->padding = '0';
	if (*str == '.')
	{
		data->precision = 1;
		data->padding = ' ';
	}
	if (data->precision == 1 && (*str >= '0' && *str <= '9'))
		data->max_width = ft_atol(str, &size);
	if (data->precision == 0 && (*str >= '0' && *str <= '9'))
		data->min_width = ft_atol(str, &size);
	if (data->precision == 0 && *str == '*')
		data->min_width = va_arg(list, int);
	if (data->precision == 1 && *str == '*')
		data->max_width = va_arg(list, int);
	return (size);
}

int		get_data(const char *str, va_list list, t_data *data, int *count)
{
	int i;

	i = 1;
	data->min_width = 0;
	data->max_width = 0;
	data->type = 0;
	data->direction = 0;
	data->padding = ' ';
	data->precision = 0;
	while (match(str[i], VALID_TYPE) == 0 && str[i])
	{
		if (match(str[i], VALID_FLAG))
			i += get_flags(data, str + i, list);
		else
		{
			if (str[i + 1] != '%')
				*count += ft_putchar('%');
			return (i);
		}
	}
	if (match(str[i], VALID_TYPE))
		data->type = str[i];
	return (i + 1);
}

int		compatibility_check(t_data data)
{
	return (1);
}

void	make_string(t_data data, va_list list, int *count)
{
	char	*str;

	str = NULL;
	if (data.type == 0)
		return ;
	if (data.type == 'c' || data.type == '%')
	{
		str = (char *)malloc(2);
		str[0] = data.type;
		if (data.type == 'c')
			str[0] = va_arg(list, int);
		str[1] = 0;
	}
	if (data.type == 'n')
		str = ft_itoa(data, *count);
	if (data.type == 'd' || data.type == 'i')
		str = ft_itoa(data, va_arg(list, int));
	if (data.type == 'x' || data.type == 'X' || data.type == 'p')
		str = ft_ultoa(data, va_arg(list, unsigned long));
	if (data.type == 's')
	{
		str = ft_strdup(va_arg(list, char *), data);
//		printf("string: %s\n", str);
	}
//	printf("this didnt fail yet\n");
	ft_output(str, data, count);
}
