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
//#define INPUT "%5c, %2.1s, %*u\n", 'k', "wal", 5, 34546
//#define INPUT "%*.*s\n", 6, 5, "3324545346235"
//#define INPUT "%0*d\n", 5, 3
#define INPUT "%-.*d, %5.5.*c, %0*d", 5, 6, 31, 5

int		main(void)
{
//	ft_printf(INPUT);
	printf("mine count: %d\n", ft_printf(INPUT));
//	printf("\n");
//	printf(INPUT);
	printf("real count: %d\n", printf(INPUT));
//	printf("\n");
	return (0);
}
