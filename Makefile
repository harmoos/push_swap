
SRC = $(wildcard *.c) $(wildcard libft/*.c) $(wildcard ft_printf/*.c) $(wildcard get_next_line/*.c)

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
NAME = push_swap
OBJDIR = obj/
INCLUDES = ./
HEADER = $(INCLUDES)push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft -I./get_next_line -I./ft_printf -I.

all: $(OBJDIR) $(NAME)

$(OBJDIR)libft/:
				mkdir -p $(OBJDIR)libft/

$(OBJDIR)libft/%.o: libft/%.c | $(OBJDIR)libft/
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)ft_printf/:
				mkdir -p $(OBJDIR)ft_printf/

$(OBJDIR)ft_printf/%.o: ft_printf/%.c | $(OBJDIR)ft_printf/
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)get_next_line/:
				mkdir -p $(OBJDIR)get_next_line/

$(OBJDIR)get_next_line/%.o: get_next_line/%.c | $(OBJDIR)get_next_line/
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
				mkdir $(OBJDIR)

$(OBJDIR)%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJS):		$(HEADER) | $(OBJDIR)

clean:
				$(RM) -r $(OBJDIR)

fclean:		clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re custom
