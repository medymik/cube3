NAME = cube3D
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = libft/ft_memset.c \
	   libft/ft_bzero.c \
	   libft/ft_memcpy.c \
	   libft/ft_memccpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_strlen.c \
	   libft/ft_isalpha.c \
	   libft/ft_isdigit.c \
	   libft/ft_isalnum.c \
	   libft/ft_isascii.c \
	   libft/ft_isprint.c \
	   libft/ft_toupper.c \
	   libft/ft_tolower.c \
	   libft/ft_strchr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strncmp.c \
	   libft/ft_strlcpy.c \
	   libft/ft_strlcat.c \
	   libft/ft_strnstr.c \
	   libft/ft_atoi.c \
	   libft/ft_strdup.c \
	   libft/ft_calloc.c \
	   libft/ft_substr.c \
	   libft/ft_strjoin.c \
	   libft/ft_strtrim.c \
	   libft/ft_split.c \
	   libft/ft_itoa.c \
	   libft/ft_strmapi.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \
	   helpers/ft_readfile.c \
	   helpers/ft_table.c \
	   helpers/ft_utils.c \
	   parser/ft_check.c \
	   parser/ft_error.c \
	   parser/ft_handler.c \
	   parser/ft_params.c \
	   parser/ft_parsecolor.c \
	   parser/ft_parsemap.c \
	   parser/ft_resolution.c \
	   parser/ft_textures.c \
	   parser/initializer.c \
	   parser/player.c \
	   engine/game.c \
	   engine/movement.c \
	   engine/ray.c \
	   engine/draw.c \
	   engine/sprite_draw.c \
	   engine/sprite.c \
	   engine/exit.c \
	   engine/engine.c \
	   engine/bmp.c \
	   engine/textures.c \
	   main.c \

INCLUDES = -I libft/ \
		   -I get_next_line/ \
		   -I includes/ \
		   -I parser/ \
		   -I helpers/ \

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)



all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(FRAMEWORKS) -o $(NAME)

clean : 
	/bin/rm -f $(OBJS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

bonus : $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@
