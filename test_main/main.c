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

#ifndef INPUT
#define INPUT "p5 %.3d\n", 100
#endif
//#define INPUT "%5c, %2.1s, %*u\n", 'k', "wal", 5, 34546
//#define INPUT "%*.*s\n", 6, 5, "3324545346235"
//#define INPUT "%0*d\n", 5, 3
// #define INPUT "%-.*d, %5.5.c, %0*d", 5, 6, 31, 5, 5

 void	my_printf(void)
 {
// 	printf("mine count: %d\n", ft_printf(INPUT));
	printf("mine count: %d\n", ft_printf(INPUT));
 }

int	test_shit(void)
{
	int t = 345;
//	ft_printf("t5 %50.10d\n", 10);
	ft_printf("neg7 %*.*d\n", -1586, 15, 0);
	printf("neg7 %*.*d\n", -1586, 15, 0);
	return(0);
}

int		main(int argc, char **argv)
{
// 	ft_printf(INPUT);
	return (test_shit());
	my_printf();
	printf("\n");
	printf("real count: %d\n", printf(INPUT));
//	ft_printf(INPUT);
}
