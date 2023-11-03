NAME = pushswap
MAKE_LIBFT = make -C ./dependencies/libft

FILES = main.c				\
		input_transformer.c	\
		errors_handler.c	\
		stack.c				\
		calculate.c			\

LIBFT_FLAGS = -L./dependencies/libft -l:libft.a
OBJ_DIRECTORY = ./.obj/

CC = cc

FLAGS = -c -Wall -Wextra -Werror -g3

INCLUDES = ./includes/push_swap.h
SOURCES = $(addprefix "sources/", $(SRCS:.c=.o))
OBJS = $(addprefix $(OBJ_DIRECTORY), $(FILES:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIRECTORY)%.o: ./sources/%.c Makefile $(INCLUDES)
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