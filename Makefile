all:
	gcc -c biblioteca.c -lncurses -Wall 
	gcc jogo.c -o jogo biblioteca.o -lncurses -Wall

clean:
	rm -rf *.o jogo
