poker : poker_holdem.o combinaisons.o main.o
	g++ -o poker *.o

poker_holdem.o : poker_holdem.hpp defines.hpp poker_holdem.cpp
	g++ -c poker_holdem.cpp

main.o : poker_holdem.hpp main.cpp
	g++ -c main.cpp

combinaisons.o : poker_holdem.hpp combinaisons.cpp
	g++ -c combinaisons.cpp

clean:
	rm -rf *.o

mrproper:
	rm -rf poker
