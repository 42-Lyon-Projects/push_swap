NAME = pushswap
MAKE_LIBFT = make -C ./dependencies/libft

FILES = main.c						\
		parsing/input_transformer.c	\
		parsing/errors_handler.c	\
		stack.c						\
		node.c						\
		utils.c						\
		movements/push_movement.c	\
		movements/reverse_movement.c\
		movements/rotate_movement.c	\
		movements/swap_movement.c	\
		algorithms/two_numbers.c	\
		algorithms/three_numbers.c	\
		algorithms/four_numbers.c	\
		algorithms/five_numbers.c	\
		algorithms/more_numbers.c	\


LIBFT_FLAGS = -L./dependencies/libft -l:libft.a
OBJ_DIRECTORY = ./.obj/

CC = cc

#FLAGS = -c -Wall -Wextra -Werror -g3
FLAGS = -c -g3

INCLUDES = ./includes/push_swap.h
SOURCES = $(addprefix "sources/", $(SRCS:.c=.o))
OBJS = $(addprefix $(OBJ_DIRECTORY), $(FILES:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIRECTORY)%.o: ./sources/%.c Makefile $(INCLUDES)
	$(CC) $(FLAGS) $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY)/movements $(OBJ_DIRECTORY)/parsing

all : $(NAME)

clean :
	$(RM) $(NAME)
	rm -rf $(OBJ_DIRECTORY)

fclean : clean
	rm -rf $(NAME)

re : fclean all