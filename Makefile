# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/13 13:12:10 by tbruinem       #+#    #+#                 #
#    Updated: 2019/12/16 12:51:50 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atol.c\
		ft_digit_utils.c\
		ft_parse_utils.c\
		ft_parser.c\
		ft_pointer_utils.c\
		ft_printf.c\
		ft_putchar.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_string_utils.c\
		ft_strings.c\
		ft_strlen.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

INPUT = "%s", "string"

%.o: %.c
	gcc -Wall -Wextra -Werror $^ -I. -c

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all
