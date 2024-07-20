##
# Rush-02
#
# @file
# @version 0.1

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: rush-02

rush-02: main.c string.o libft.o
	$(CC) $(CFLAGS) -o $@ main.c string.o libft.o

string.o: string.c
	$(CC) $(CFLAGS) -c -o $@ string.c

libft.o: libft.c
	$(CC) $(CFLAGS) -c -o $@ libft.c

fclean: ; rm -f rush-02 string.o libft.o

# end
