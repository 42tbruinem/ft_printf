/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:21:31 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/30 19:32:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		ptr = (char *)&str[i];
	return (ptr);
}
