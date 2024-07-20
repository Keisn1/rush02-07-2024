##
# Rush02
#
# @file
# @version 0.1

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: rush-02

rush-02: main.c example2.o example3.o
	$(CC) $(CFLAGS) -o $@ main.c example2.o example3.o

example2.o: example2.c
	$(CC) $(CFLAGS) -c -o $@ example2.c

example3.o: example3.c
	$(CC) $(CFLAGS) -c -o $@ example3.c

fclean: ; rm -f rush-02 example2.o example3.o

# end
