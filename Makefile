CC=gcc
LIBS=-lncurses -lmenu

all:
	@${CC} -c diagram.c -o diagram.o ${LIBS}
	@${CC} -c diag_menu.c -o diag_menu.o ${LIBS}
	@${CC} -o main main.c diag_menu.o diagram.o ${LIBS}
	@rm diagram.o diag_menu.o

clean:
	@rm main
