/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:45:26 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/09 19:01:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_flags(t_data *data, const char *str, va_list list)
{
	int size;

	size = 1;
	if (*str == '-')
	{
		data->direction = 1;
		data->padding = ' ';
	}
	else if (*str == '0' && data->direction == 0 && data->precision == 0)
		data->padding = '0';
	else if (*str == '.' && data->precision == 0)
	{
		data->precision = 1;
		data->padding = ' ';
	}
	else if (data->precision == 1 && is_digit(*str) && data->max_width == 0)
		data->max_width = ft_atol(str, &size);
	else if (data->precision == 0 && is_digit(*str) && data->min_width == 0)
		data->min_width = ft_atol(str, &size);
	else if (data->precision == 0 && *str == '*' && data->min_width == 0)
		data->min_width = va_arg(list, int);
	else if (data->precision == 1 && *str == '*' && data->max_width == 0)
		data->max_width = va_arg(list, int);
	return (size);
}

void	compatibility_check(t_data *data, int *count)
{
	if (data->type == 0)
		*count = -1;
	if (data->max_width < 0)
	{
		data->precision = 0;
		data->max_width = 0;
	}
	if (data->min_width < 0)
	{
		data->direction = 1;
		data->padding = ' ';
		data->min_width = data->min_width * -1;
	}
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
		if (match(str[i], VALID_FLAG) == 1)
			i += get_flags(data, str + i, list);
		else
			break ;
	}
	if (match(str[i], VALID_TYPE))
		data->type = str[i];
	if (str[i] == 0)
		i--;
	compatibility_check(data, count);
	return (i);
}

void	make_string(t_data data, va_list list, int *count)
{
	char	*str;

	str = NULL;
	if (data.type == 'c' || data.type == '%')
		str = ft_convert_c(data, list);
	if (data.type == 'n')
		str = ft_itoa(data, *count);
	if (data.type == 'd' || data.type == 'i')
		str = ft_itoa(data, va_arg(list, int));
	if ((data.type == 'x' || data.type == 'X') ||
		(data.type == 'u' || data.type == 'o'))
		str = ft_ultoa(data, va_arg(list, unsigned int));
	if (data.type == 'p')
		str = ft_ultoa(data, va_arg(list, unsigned long));
	if (data.type == 's')
		str = ft_strdup(va_arg(list, char *), data);
	if (str == NULL || data.type == 0)
	{
		*count = -1;
		return ;
	}
	ft_output(str, data, count);
}
