# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/13 13:12:10 by tbruinem       #+#    #+#                 #
#    Updated: 2019/11/30 22:03:01 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = *.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

%.o: %.c
	gcc -Wall -Wextra -Werror $^ -I. -c

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

test: $(SRCS)
	gcc -Wall -Wextra -Werror $(SRCS) -I. -o test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all
