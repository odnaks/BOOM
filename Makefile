# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2019/04/03 19:36:07 by ebednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem
SRC = ./src/main.c \
		./src/map_test.c \
		./src/vector_funcs.c \
		./src/engine.c \
		./src/init.c \
		./src/events.c \
		./src/movement.c \
		./src/textures.c \
		./src/scaler.c \
		./src/sprites.c
LIBFT = ./libft/libft.a
OBJECTS = $(SRC:.c=.o)
WWW = -Wall -Wextra -Werror -Ofast
INCLUDES = -I libft -I includes/ -I includes/frameworks/SDL2.framework/Versions/A/Headers -I includes/frameworks/SDL2_image.framework/Versions/A/Headers
SDL =  -framework SDL2 -F includes/frameworks/ -framework SDL2_image -F includes/frameworks/ 
FLAGS_LINUX = -I ./includes/ -I includes/frameworks/SDL2.framework/Versions/A/Headers -I \
	includes/frameworks/SDL2_image.framework/Versions/A/Headers -lm -lpthread -lSDL2main -lSDL2 -I libft -lSDL2_image

all: $(NAME)

linux:
	make re -C libft/
	make re -C map_editor/
	sudo gcc $(WWW) $(SRC) $(LIBFT) $(FLAGS_LINUX) -o $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	make -C map_editor/
	make -C kiss_sdl/
	gcc -o $(NAME) $(OBJECTS) $(INCLUDES) $(SDL) $(LIBFT) 

%.o: %.c
	gcc $(WWW) $(INCLUDES) -F ~/Library/Frameworks/ -c $< -o $@ 

clean:
	make clean -C libft/
	make clean -C map_editor/
	/bin/rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	make fclean -C map_editor/
	/bin/rm -f $(NAME)

re: fclean all

re_linux: fclean linux
