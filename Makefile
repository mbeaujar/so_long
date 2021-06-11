NAME=so_long
CC=clang
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
RM=rm -f
HEADER=include
LIB_MLX=minilibx_opengl/libmlx.a
LIB_FT=libft/libftmacos.a
PATH_LIB=libft/
PATH_MLX=minilibx_opengl
FLAGS_MLX=-framework OpenGL -framework Appkit 
LIBRARY= -Llibft -lftmacos -Lminilibx_opengl -lmlx

SRCS = source/main.c \
	source/parsing/ft_strjoin.c \
	source/parsing/parse_map.c \
	source/parsing/parsing.c \
	source/key/arrow.c \
	source/key/key.c \
	source/engine/draw.c

OBJS = ${SRCS:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $<  -I$(HEADER) -c -o $@

all : $(NAME)

$(NAME) : $(OBJS)
ifeq ("$(wildcard minilibx_opengl/libmlx.a)","")
	@make -C minilibx_opengl
endif
ifeq ("$(wildcard libft/libftmacos.a)","")
	@make re -C libft
endif
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) $(FLAGS_MLX) -o $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(OBJS)

re : fclean all