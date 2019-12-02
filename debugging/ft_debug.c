/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_debug.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 13:11:09 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/30 13:11:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_data(t_data data)
{
	printf("\n---DEBUGGING:DATA---\n");
	printf("Padding:   %c\n", data.padding);
	printf("Min_width: %d\n", data.min_width);
	printf("Type:      %c\n", data.type);
	printf("Max_width: %d\n", data.max_width);
	printf("Direction: %d\n", data.direction);
	printf("Precision: %d\n", data.precision);
	printf("--------------------\n");
}
