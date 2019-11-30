/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:16:33 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/30 18:54:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	list;
	t_data	data;
	int		count;

	count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != 0)
		{
			str += get_data(str, list, &data, &count) - 1;
			make_string(data, list, &count);
		}
		else if (*str == '%' && *(str + 1) == 0)
			count = -1;
		else
			count += ft_putchar(*str);
		if (count == -1)
			break ;
		str++;
	}
	va_end(list);
	return (count);
}
