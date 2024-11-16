CC=gcc
FLAGS=-O3 -Wall -Wextra -Werror

all: main.c
	$(CC) main.c -o TheLang $(FLAGS) -lm
