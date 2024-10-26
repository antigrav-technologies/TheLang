CC=gcc
FLAGS=-O3 -Wall -Wextra -Werror

all:
	$(CC) main.c -o TheLang $(FLAGS) -lm