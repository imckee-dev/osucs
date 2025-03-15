CC=g++ -std=c++11 -g
exe=asm4

# Complete the makefile
# Your code here: 
EXE_FILE = run4

all: $(EXE_FILE)     

$(EXE_FILE): bats.o event.o game.o gold.o room.o stalactites.o wumpus.o main.o
	$(CC) $(CFLAGS) bats.o event.o game.o gold.o room.o stalactites.o wumpus.o main.o -o $(EXE_FILE)

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.out *.o $(EXE_FILE)
	clear
