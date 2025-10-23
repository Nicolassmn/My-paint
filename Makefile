##
## EPITECH PROJECT, 2023
## header*
## File description:
## lolm
##

SRC     =	src/main.c											\
			src/animation/animation.c							\
			src/gestion_button/button.c							\
			src/soundbox/soundbox.c								\
			src/shape/basic_shape.c								\
			src/loading/load.c									\
			src/menu/menu.c										\
			src/paint/paint.c									\
			src/paint/picture.c									\
			src/paint/handle_mouse.c							\
			src/paint/handle_event.c							\
			src/paint/init_texture.c							\
			src/paint/draw_asset_cursor.c						\
			src/paint/handle_colors/update.c 					\
			src/paint/handle_colors/inits_colors.c 				\
			src/paint/handle_colors/handle_colors.c 			\
			src/paint/handle_colors/init_start_grad.c 			\
			src/paint/handle_palette_color.c					\
			src/str_function/my_strdup.c						\
			src/str_function/my_strcmp.c						\
			src/str_function/my_strcpy.c						\
			src/str_function/my_strlen.c						\
			src/str_function/str_to_double.c					\
			src/str_function/my_strcat.c						\
			src/paint/handle_button.c							\
			src/paint/handle_button_two.c						\

OBJ		=	$(SRC:.c=.o)
NAME	=	my_paint

CC		=	gcc
CFLAGS	=	-Wextra -Wall -W -I ./include/ -lm -g
CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	rm -f *.c~ $(OBJ)

fclean: clean
	rm -f $(NAME)

debug: CFLAGS += -g
debug: all

push: fclean
	@read -p "gitmoji : " g;		\
	read -p "commit : " c;	 		\
	git add *; 						\
	git commit -m "[ :$$g: ] : $$c";	\
	git push

re: fclean all

.PHONY: all clean fclean re debug
