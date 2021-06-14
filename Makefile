
UNAME=$(shell uname)

ifeq ($(UNAME), Darwin)
	CFLAGS = -D MACOS=1
	LIB_MLX=minilibx_opengl/libmlx.a
	PATH_MLX=minilibx_opengl
	FLAGS_MLX=-framework OpenGL -framework Appkit 
	LIBRARY= -Llibft -lftmacos -Lminilibx_opengl -lmlx
	LIB_FT=libft/libftmacos.a
endif
ifeq ($(UNAME), Linux)
	CFLAGS = -D LINUX=1
	LIB_MLX=minilibx_linux/libmlx.a
	PATH_MLX=minilibx_linux
	LIBRARY= -Llibft -lftlinux -Lminilibx_linux -lmlx
	FLAGS_MLX=-L/usr/lib -lXext -lX11 -lm
	LIB_FT=libft/libftlinux.a
endif

NAME=so_long
CC=clang
CFLAGS += -Wall -Wextra -Werror
RM=rm -f
HEADER=include
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
ifeq ("$(wildcard $(LIB_MLX))","")
	@make -C $(PATH_MLX)
endif
ifeq ("$(wildcard $(LIB_FT))","")
	@make re -C $(PATH_LIB)
endif
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) $(FLAGS_MLX) -o $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(OBJS)

re : fclean all