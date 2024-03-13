NAME = push_swap
NAME_BONUS = checker

LIBFT = libft/libft.a

SRC = main.c tools_list.c tools_list2.c tools.c tools2.c tools_moves.c tools_moves2.c \
	  ./moves/push_moves.c ./moves/retate_moves.c ./moves/rev_retate_moves.c ./moves/swap_moves.c \
	  ./sorts/sort_three.c ./sorts/sort_four.c  ./sorts/sort_five.c

SRC_BONUS = checker_bonus.c tools_list.c tools_list2.c tools.c tools2.c tools_moves.c tools_moves2.c \
	  ./moves/push_moves.c ./moves/retate_moves.c ./moves/rev_retate_moves.c ./moves/swap_moves.c \
	  ./sorts/sort_three.c ./sorts/sort_four.c  ./sorts/sort_five.c \
	 ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o)
OBJSB = $(SRC_BONUS:.c=.o) 

CC = cc

%.o : %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

bonus : $(NAME_BONUS)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -Wall -Wextra -Werror $(OBJ) $(LIBFT) -o push_swap

$(NAME_BONUS) : $(OBJSB) $(LIBFT)
	$(CC) -Wall -Wextra -Werror $(OBJSB) $(LIBFT) -o checker

clean:
	rm -rf $(OBJ) $(OBJSB)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all