NAME2 = push_swap
NAME1 = checker
LIBFT = ./libft/libft.a
FILES2 =	push_swap.c\
			array_funcs.c\
			stack.c\
			other_stack_funcs.c\
			sort_funcs.c\
			sort_misc_funcs.c\
			freeall.c\
			read_funcs.c\
			shared_funcs.c\
			hardcoded_algo.c

FILES1 = 	checker.c\
			array_funcs.c\
			stack.c\
			other_stack_funcs.c\
			read_funcs.c\
			freeall.c\
			shared_funcs.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
FLAGS		=  -Wall -Werror -Wextra
HEADER		= push_swap.h

all: $(NAME2) $(NAME1)

$(LIBFT):
	$(MAKE) -sC libft all

$(NAME1): $(OBJ1)
	gcc -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(OBJ2)
	gcc -o $(NAME2) $(OBJ2) $(LIBFT)

%.o: %.c $(HEADER) $(LIBFT)
	gcc -I . -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all