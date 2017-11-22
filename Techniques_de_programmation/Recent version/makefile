#all  : Secours

Secours : ./obj/alerte.o ./obj/unite.o ./obj/menu.o ./obj/main.o
		cc -o Secours ./obj/main.o ./obj/menu.o ./obj/unite.o ./obj/alerte.o

./obj/alerte.o : ./header/alerte.h ./src/alerte.c
	cc -c ./src/alerte.c

./obj/unite.o : ./header/unite.h ./src/unite.c
	cc -c ./src/unite.c

./obj/main.o : ./header/alerte.h ./header/unite.h ./src/main.c
	cc -c ./src/main.c

./obj/menu.o : ./header/alerte.h ./header/unite.h ./src/menu.c
	cc -c ./src/menu.c
