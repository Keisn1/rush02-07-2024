##
# Rush-02
#
# @file
# @version 0.1

# ------------------- VARIABLES ----------------------------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FSANITIZE_FLAG = -fsanitize=address

NAME = rush-02

MY_SOURCES = 	main.c 			\
				string.c 		\
				libft.c			\
				errors.c		\
				spell_node.c	\
				places.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CUR_DIR = $(shell pwd)

# ------------------- RULES ----------------------------------------
# calls the first rule that it finds in the file
$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(FSANITIZE_FLAG) -o $(NAME) $(MY_OBJECTS)

fclean: ; rm -f rush-02 $(MY_OBJECTS)

# end
