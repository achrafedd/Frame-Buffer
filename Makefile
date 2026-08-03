CC = cc
CFLAGS += -Wall -Wextra -Werror -Iincludes
NAME = framebuffer
SRCS = src/main.c
OBJS = $(SRCS: src/%.c=obj/%.o)

obj/%.o: src/%.c
	@mkdir obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) ./includes/framebuffer.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf ./obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
