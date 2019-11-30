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

#define INPUT "%p, %5.2d, %5c, %9s, %*x\n", &arr, -234, 'k', NULL, 5, 3454687454
//#define INPUT "%5c, %2.1s, %*x\n", 'k', "wal", 5, 345468745435345

int		main(int argc, char **input)
{
	char arr[40];
	char *str;
	long adress;
	int n;

	n = -3245;
	printf("mine count: %d\n", ft_printf(INPUT));
	printf("real count: %d\n", printf(INPUT));
	return (0);
}
