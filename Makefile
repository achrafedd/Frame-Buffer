CC = cc
CFLAGS +=  -Iincludes -lm #-Wall -Wextra -Werror
NAME = framebuffer
SRCS = src/main.c src/fb_init.c src/fb_destroy.c src/put_pixel.c src/fb_fill_rect.c
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
