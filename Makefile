NAME = push_swap
NAME_BONUS = checker

SRC = main.c tools_list.c tools_list2.c tools.c tools2.c tools_moves.c tools_moves2.c \
	  ./moves/push_moves.c ./moves/retate_moves.c ./moves/rev_retate_moves.c ./moves/swap_moves.c \
	  ./sorts/sort_three.c ./sorts/sort_four.c  ./sorts/sort_five.c

SRC_BONUS = checker_bonus.c tools_bonus.c tools_list.c tools_list2.c tools.c tools2.c tools_moves.c tools_moves2.c \
	  ./moves/push_moves.c ./moves/retate_moves.c ./moves/rev_retate_moves.c ./moves/swap_moves.c \
	  ./sorts/sort_three.c ./sorts/sort_four.c  ./sorts/sort_five.c \
	 ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o)
OBJSB = $(SRC_BONUS:.c=.o) 

CC = cc

%.o : %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -Wall -Wextra -Werror $(OBJ) libft/libft.a -o push_swap

bonus : $(OBJSB)
	make -C libft
	$(CC) -Wall -Wextra -Werror $(OBJSB) libft/libft.a -o checker

clean:
	rm -rf $(OBJ) $(OBJSB)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all