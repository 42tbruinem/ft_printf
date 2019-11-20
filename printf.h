/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:16:53 by tbruinem       #+#    #+#                */
/*   Updated: 2019/11/19 16:05:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
t_data			get_data(const char *str, va_list list);
int				compatibility_check(t_data data);
int				make_string(t_data data, va_list list);
char			*ft_strdup(const char *s1);
char			*ft_itoa(t_data data, long long nb);
int				ft_atoi(const char *str);
int				match(char c, char *set);
int				ft_putstr(const char *str);

#endif
