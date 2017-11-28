Secours : alerte.o unite.o menu.o main.o
	cc -o Secours main.o menu.o unite.o alerte.o

alerte.o : alerte.h alerte.c
	cc -c alerte.c

unite.o : unite.h unite.c
	cc -c unite.c

main.o : alerte.h unite.h main.c
	cc -c main.c

menu.o : alerte.h unite.h menu.c
	cc -c menu.c
