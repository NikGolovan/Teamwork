all  : Secours



alerte.o : alerte.h alerte.c
	cc -c alerte.c

unite.o : unite.h unite.c
	cc -c unite.c

main.o : alerte.h unite.h main.c
	cc -c main.c

Secours : alerte.o unite.o main.o
		cc -o Secours main.o unite.o alerte.o
