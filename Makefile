NAME = fdf

INC_DIR := include
SRC_DIR := srcs
SRCS := parse.c map_size.c transform.c #drawline.c 
OBJS := parse.o map_size.o transform.o #drawline.o 

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^ \
	-L ./get_next_line \
	-L ./Libft \
	-lgetnextline \
	-lft

%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR)\
		-o $@ -c $<

clean :
	-rm ./fdf

re : clean all
