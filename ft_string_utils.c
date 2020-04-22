/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 18:56:57 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/09 18:57:04 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_calloc(int size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * size);
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
