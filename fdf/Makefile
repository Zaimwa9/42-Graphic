NAME = fdf

SRC_PATH = ./srcs/
OBJ_PATH = ./srcs/
INC_PATH = ./includes/

FILES = main.c parser.c draw.c hooks_handler.c rotate.c translate.c zoom.c \
		colors.c

SRCS = $(addprefix $(SRC_PATH), $(FILES))
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

HEADERS = -I/includes
FLAGS = -Werror -Wextra -Wall

.PHONY: all clean fclean re

APPKIT = -framework AppKit
OPENGL = -framework OpenGL
MLX = -lmlx

all: $(NAME)

$(NAME): $(OBJS)
	@echo "fdf will be done..."
	@make -C libft
	@gcc $(FLAGS) $(LIBFT) $(HEADERS) $(OBJS) $(MLX) $(OPENGL) $(APPKIT) -o $(NAME)
	@echo "fdf done!"

srcs/%.o: srcs/%.c
	@gcc -o $@ -c $< $(INCLUDES) $(FLAGS)

srcs/libft/%.o: srcs/libft/%.c
	@gcc -o $@ -c $< $(INCLUDES) $(FLAGS)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@echo "Cleaning all the shit mylord !"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
