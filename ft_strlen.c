/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 12:58:42 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/02 19:02:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *str, t_data data)
{
	size_t i;

	i = 0;
	if (data.type == 'c' || data.type == '%')
		return (1);
	while (str[i])
		i++;
	return (i);
}
