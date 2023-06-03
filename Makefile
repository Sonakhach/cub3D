NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard ./src/*.c) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

MLX = -lmlx -framework OpenGL -framework Appkit

INCLUDES = -Ilibft  -I./include

LINKERS	= -L./libft  

LINKERLIBFT = ./libft/libft.a

LIBFT = ./libft

HEADER = $(wildcard ./src/*.h)

RM = rm -f

%.o: %.c  ${HEADER} Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME) 
	
$(NAME): $(OBJS) $(LINKERLIBFT) 
	$(CC) $(CFLAGS) $(MLX) $(LINKERS) $(LINKERLIBFT) $(INCLUDES) $(OBJS) -o $(NAME)

$(LINKERLIBFT) :
	$(MAKE) -C $(LIBFT)

clean:
	@$(MAKE) clean -C $(LIBFT)

	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)	
	
	@$(RM) $(NAME)
	@echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

re: fclean all

norm:
	@norminette $(SRCS)

.PHONY: all clean fclean re
