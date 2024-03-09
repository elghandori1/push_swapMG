NAME = push_swap

SRC = main.c tools_list.c tools_list2.c tools.c tools2.c tools_moves.c tools_moves2.c \
	  ./moves/push_moves.c ./moves/retate_moves.c ./moves/rev_retate_moves.c ./moves/swap_moves.c \
	  ./sorts/sort_three.c ./sorts/sort_four.c  ./sorts/sort_five.c

OBJ = $(SRC:.c=.o) 

CC = cc

%.o : %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -Wall -Wextra -Werror $(OBJ) libft/libft.a -o push_swap

clean:
	rm -rf $(OBJ) $(OBJSB)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all