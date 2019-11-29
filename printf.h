/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:16:53 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/29 14:36:32 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//	REMOVE THIS://

#include <stdio.h>




#ifndef PRINTF_H
# define PRINTF_H

# define VALID_TYPE "cspdiuxX%"
# define VALID_FLAG	"-0.*"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_data
{
	char		type;
	int			min_width;
	int			max_width;
	char		padding;
	int			direction;
	int			precision;
}				t_data;

int				ft_printf(const char *str, ...);
int				get_data(const char *str, va_list list, t_data *data);
int				compatibility_check(t_data data);
void			make_string(t_data data, va_list list, int *count);
char			*ft_strdup(const char *s1);
char			*ft_itoa(t_data data, long long nb);
int				ft_atoi(const char *str);
int				match(char c, char *set);
int				ft_putstr(const char *str);

#endif
