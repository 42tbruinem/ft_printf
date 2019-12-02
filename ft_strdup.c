/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:40:17 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/02 17:49:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *s1, t_data data)
{
	int		i;
	int		len;
	char	*dup;

	len = 0;
	if (s1 == NULL)
		return (ft_strdup("(null)", data));
	while (s1[len])
		len++;
	if (len > data.max_width && data.precision == 1)
		len = data.max_width;
	dup = ft_calloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
