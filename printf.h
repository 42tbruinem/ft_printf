/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:16:53 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/02 18:36:00 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define VALID_TYPE "cspdiuxXo%"
# define VALID_FLAG	"-0.*123456789"

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
char			*ft_calloc(int size);
int				match(char c, char *set);
int				is_digit(char c);
int				get_data(const char *str, va_list list, t_data *data,
				int *count);
void			compatibility_check(t_data *data, int *count);
void			make_string(t_data data, va_list list, int *count);
char			*ft_itoa(t_data data, int nb);
long long		ft_atol(const char *str, int *size);
int				match(char c, char *set);
int				ft_putstr(const char *str, t_data data);
void			ft_output(char *str, t_data data, int *count);
size_t			ft_strlen(const char *str);
int				ft_putchar(char c);
char			*ft_convert_int(t_data data, long long nb);
char			*ft_strdup(const char *s1, t_data data);
void			zero_pad(char *str, int size);
char			*ft_ultoa(t_data data, unsigned long nb);

#endif
