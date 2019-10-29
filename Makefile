NAME2 = push_swap
NAME1 = checker
FILES2 = push_swap.c
FILES1 = checker.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
FLAGS		=  -Wall -Werror -Wextra
HEADER		= push_swap.h

all: $(NAME)

.PHONY: clean fclean re

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	gcc -o $(NAME1) $(OBJ1) ./libft/libft.a
	gcc -o $(NAME2) $(OBJ2) ./libft/libft.a

%.o: %.c $(HEADER)
	gcc -I . $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME1) $(OBJ2) && $(MAKE) fclean -C ./libft

re: fclean all
