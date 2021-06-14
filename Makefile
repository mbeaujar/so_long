
OS=$(shell uname)

ifeq ($(OS), Darwin)
	LIB_MLX=minilibx_opengl/libmlx.a
	PATH_MLX=minilibx_opengl
	FLAGS_MLX=-framework OpenGL -framework Appkit 
	LIBRARY= -Llibft -lftmacos -Lminilibx_opengl -lmlx
endif
ifeq ($(OS), Linux)
	LIB_MLX=minilibx_linux/libmlx.a
	PATH_MLX=minilibx_linux
	FLAGS_MLX=-L/usr/lib -lXext -lX11 -lm
	LIBRARY= -Llibft -lftmacos -Lminilibx_linux -lmlx
endif

NAME=so_long
CC=clang
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
RM=rm -f
HEADER=include
LIB_FT=libft/libftmacos.a
PATH_LIB=libft/

SRCS = source/main.c \
	source/parsing/ft_strjoin.c \
	source/parsing/parse_map.c \
	source/parsing/parsing.c \
	source/key/arrow.c \
	source/key/key.c \
	source/engine/draw.c \
	source/engine/texture.c \
	source/engine/sprites.c

OBJS = ${SRCS:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $<  -I$(HEADER) -c -o $@

all : $(NAME)

$(NAME) : $(OBJS)
ifeq ("$(wildcard minilibx_opengl/libmlx.a)","")
	@make -C $(PATH_MLX)
endif
ifeq ("$(wildcard libft/libftmacos.a)","")
	@make re -C $(PATH_LIB)
endif
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) $(FLAGS_MLX) -o $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(OBJS)

re : fclean all