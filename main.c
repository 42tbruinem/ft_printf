/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 12:23:32 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/30 12:23:32 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

//#define INPUT "%%b"
#define INPUT "%5c, %2.1s, %*u\n", 'k', "wal", 5, 34546

int		main(void)
{
	printf("mine count: %d\n", ft_printf(INPUT));
//	printf("\n");
	printf("real count: %d\n", printf(INPUT));
	return (0);
}
