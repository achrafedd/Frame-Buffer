CC = cc
CFLAGS += -Wall -Wextra -Werror -Iincludes
NAME = framebuffer
SRCS = src/main.c src/fb_init.c src/fb_destroy.c
OBJS = $(SRCS:src/%.c=obj/%.o)

obj/%.o: src/%.c
	@mkdir -p obj
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
