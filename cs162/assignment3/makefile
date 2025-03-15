# Define Makefile variables
CC = g++ -std=c++11 -g
# CFLAGS = -Wall -Werror    # Uncomment to use, stricter compiling
EXE_FILE = runassignment

# Format:
# target: <prerequisites/dependencies (optional)>
#     <commands>
#     ...
#  ^  makefiles require tab indents here (throws error)

# run "make" with no target will do first target in makefile ("all" in this case)
all: $(EXE_FILE)     

# Compile and link files into executable called $(EXE_FILE) (main)
$(EXE_FILE): coffee.o display.o menu.o order.o prog.o shop.o
	$(CC) $(CFLAGS) coffee.o display.o menu.o order.o prog.o shop.o -o $(EXE_FILE)

# coffee.o display.o menu.o order.o prog.o shop.o
coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

display.o: display.cpp display.h
	$(CC) -c display.cpp

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp

prog.o: prog.cpp
	$(CC) -c prog.cpp

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp



# run "make clean" to use this rule, also an example of how to run multiple commands
clean:
	rm -f *.out *.o $(EXE_FILE)
	clear
