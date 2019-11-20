/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_wchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 18:11:20 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/19 19:24:04 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "printf.h"

void print_bits(unsigned int x)
{
    int i;
	char bit;

	i = 8 * 2;
	while (i >= 0)
	{
		bit = ((x >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

int		main(void)
{
	print_bits(L'ø');
	return (0);
}

while (bytes_read != 0)
{



}
