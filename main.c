/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:16:33 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/29 14:39:21 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_validate_input(const char *str, va_list list)
{
	int		i;
	t_data	data;
	va_list	cpy;

	va_copy(cpy, list);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			get_data(str + i, cpy, &data);
			if (compatibility_check(data) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

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
			str += get_data(str + 1, list, &data);
			make_string(data, list, &count);
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	va_end(list);
	return (count);
}

int		main(int argc, char **input)
{
	char arr[40];
	char *str;
	long adress;
	int n;

	n = ft_printf("dwfdg");
//	printf("\n%d\n", n);
	str = &arr[4];
	adress = (long)str;
//	printf("%#lx\n", (long)str);
//	printf("%p\n", (long)str);
	return (0);
}