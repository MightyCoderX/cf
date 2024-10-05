CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23

SRC_FILES = main.c cf.c


main: ${SRC_FILES}
	${CC} ${CFLAGS} -g -Wno-unused ${SRC_FILES} -o ./$@
