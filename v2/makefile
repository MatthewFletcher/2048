# target: dependencies
# 	action

#Create output file named output
output: main.o Number.o Game.o 
	g++ main.o Number.o Game.o  -o output
	rm *.o


main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Number.o: Number.cpp Number.h
	g++ -c Number.cpp





clean:
	rm *.o
	rm output
