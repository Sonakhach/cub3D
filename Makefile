NAME = cub3d

CC = cc

CFLAGS =   -ggdb3  -Wall -Wextra -Werror #-fsanitize=memory -g  #-Werror #-fstack-protector-all 
SRCS = $(wildcard ./src/*.c) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

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
	$(CC) $(CFLAGS) $(LINKERS) $(LINKERLIBFT) $(INCLUDES) $(OBJS) -o $(NAME)

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
