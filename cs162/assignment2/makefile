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
$(EXE_FILE): catalog.o run_catalog.o
	$(CC) $(CFLAGS) catalog.o run_catalog.o -o $(EXE_FILE)

# Compile with "-c" flag to create object files
catalog.o: catalog.cpp
	$(CC) $(CFLAGS) -c catalog.cpp

run_catalog.o: run_catalog.cpp
	$(CC) -c run_catalog.cpp

# run "make clean" to use this rule, also an example of how to run multiple commands
clean:
	rm -f *.out *.o $(EXE_FILE)
	clear
