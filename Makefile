NAME = pushswap
MAKE_LIBFT = make -C libft

SRCS =  main.c				\
		input_transformer.c	\
		errors_handler.c	\

LIBFT_FLAGS = -L./libft -l:libft.a
OBJ_DIRECTORY = ./.obj/

CC = cc

FLAGS = -c -Wall -Wextra -Werror -g3
INCLUDES = ./push_swap.h
OBJS = $(addprefix $(OBJ_DIRECTORY), $(SRCS:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIRECTORY)%.o: %.c Makefile $(INCLUDES)
	$(CC) $(FLAGS) $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY)

all : $(NAME)

clean :
	$(RM) $(NAME)
	rm -rf $(OBJ_DIRECTORY)

fclean : clean
	rm -rf $(NAME)

re : fclean all