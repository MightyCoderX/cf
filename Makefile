CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c2x

SRC_FILES = main.c cf.c


main: ${SRC_FILES}
	${CC} ${CFLAGS} ${SRC_FILES} -o ./$@
