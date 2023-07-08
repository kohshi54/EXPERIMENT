NAME = garbage
CC = cc
CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=address

SRCS = 	gc.c

OBJS = $(SRCS:%.c=%.o)

LIBFT = libft/libft.a
LIBFTDIR = libft/

INCLUDES = gc.h

LIBFLAGS = -L./$(LIBFTDIR) -lft -lreadline

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(LIBFT) : $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re : fclean all

.PHONY : clean fclean re all