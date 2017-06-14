# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 12:54:42 by ele-cren          #+#    #+#              #
#    Updated: 2017/06/14 17:41:13 by ele-cren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = rt

SRC = src/check_types.c src/init.c src/main.c src/parse_lights.c \
	  src/parsing.c src/parse_objects.c src/parse_cam.c src/sdl.c \
	  src/list.c src/error.c src/browse.c src/calc_obj.c src/init2.c \
	  src/draw.c

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -I ./SDL2/SDL2/include  -I ./libft/include \
		-I ./include -g

LIBS = -L./libft -lft -L/tmp/SDL2/SDL2/lib -lSDL2 -lSDL2main

HEADER = include/rt.h libft/include/libft.h

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS) $(SDLLIBS)
	echo "\033[32m[✔] \033[0m$(NAME)"

obj/%.o : src/%.c $(HEADER)
	test -e /tmp/SDL2/SDL2 || (cd SDL2/SDL2 ; \
		./configure --prefix=/tmp/SDL2/SDL2 ; make install ; cd -)
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@
	echo "\033[32m[✔] \033[0m$@"

.PHONY : clean fclean

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31m[✗] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31m[✗] \033[0m$(NAME)"

re : fclean all
