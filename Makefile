NAME = push_swap

LIBFT = libft/libft.a

S = srcs/
O = objs/
I = incl/
L = libft/

all: $(NAME)

.PHONY: all clean fclean re

CC = cc
CFLAGS += -Wall -Wextra -Werror -I$I
LDFLAGS += 

SRC = $Spush_swap.c \
		$Slinked_list_helpers.c \
		$Spush_operations.c \
		$Sreverse_operations.c \
		$Srotation_operations.c \
		$Sswap_operations.c \
		$Scount_and_validate_input.c \
		$Sinput_to_linklist.c \
		$Smini_algo.c \
		$Sgive_index.c \
		$Smedium_algos.c \

OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S% $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Project ready for use."

## delete this before eval
DEBUG_NAME = debug.out

debug: $(DEBUG_NAME)

DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

$(DEBUG_NAME): $(LIBFT) $(OBJ)
	@$(CC) $(DEBUG_FLAGS) $^ -o $@
	@echo "Debug ready for use."

cleandebug: fclean
	@rm -f $(DEBUG_NAME)
	@echo "debug.out removed"
## to here

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