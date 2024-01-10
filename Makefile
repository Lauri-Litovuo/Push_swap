NAME = push_swap

LIBFT = libft/libft.a

S = srcs/
O = objs/
I = incl/
L = libft/

all: $(NAME)

.PHONY: all clean fclean re

CC = gcc
CFLAGS += -Wall -Wextra -Werror -I$I
LDFLAGS += 

SRC = $Spush_swap.c \
		$Sadd_and_del.c \
		$Spush_operations.c \
		$Sreverse_operations.c \
		$Srotation_operations \
		$Sswap_operations \

OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@ar -cr $(NAME) $(OBJ)

$(LIBFT): $L
	@make -C $L

cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $O

cleanlibft:
	@make fclean -C $L

clean: cleanobjdir cleanlibft
	@echo "Cleaning object files and libft"

fclean: clean
	@rm -f $(NAME)
	@echo "Project file removed"

re: fclean all