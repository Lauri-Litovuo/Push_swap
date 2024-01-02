NAME = push_swap

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs
INCLUDES_DIR = ./

SOURCES = $(addprefix $(SOURCES_DIR), push_swap.c )

OBJECTS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS_DIR))

CFLAGS = -Wall -Wextra -Werro
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rsc $(NAME) $(OBJECTS)
	$(info CREATED $(NAME))

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJS_DIR)
	$(info DELETED $(OBJECTS))

fclean: clean
	@rm -f $(NAME)
	$(info DELETED $(NAME))

re: fclean all

.PHONY: all clean fclean re
