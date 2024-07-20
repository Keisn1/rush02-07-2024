##
# Rush02
#
# @file
# @version 0.1

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: example

example2.o: example2.c
	$(CC) $(CFLAGS) -c -o $@ example2.c

example3.o: example3.c
	$(CC) $(CFLAGS) -c -o $@ example3.c

example: example.c example2.o example3.o
	$(CC) $(CFLAGS) -o $@ example.c example2.o example3.o

fclean: ; rm -f example example2.o example3.o

# end
