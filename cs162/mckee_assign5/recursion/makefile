CC = g++ -g
exe_file = run

$(exe_file): stairs.o recurse.o
	$(CC) stairs.o recurse.o -o $(exe_file)

stairs.o: stairs.cpp stairs.h
	$(CC) -c stairs.cpp

recurse.o: recurse.cpp
	$(CC) -c recurse.cpp

clean:
	rm -f *.o $(exe_file)
