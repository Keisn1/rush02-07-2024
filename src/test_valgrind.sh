#!/usr/bin/env sh

cat examples.txt | xargs -L 1 valgrind --tool=memcheck --leak-check=yes  ./rush-02
