CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23

SRC_FILES = main.c cf.c dynamic_string/dynamic_string.c


main: ${SRC_FILES}
	${CC} ${CFLAGS} -g -Wno-unused ${SRC_FILES} -o ./$@

run: main
	./main

debug:
	gdb ./main

