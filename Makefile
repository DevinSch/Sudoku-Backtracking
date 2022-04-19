# Generic Makefile
# Note. Comments are preceded with #.
CCC=g++
# list all warnings
CCCFLAGS= -Wall -g -std=c++11 -lX11

# all is called a target, after the colon you have dependencies
# ie. "the target all is dependent on the executables
all : Sudoku

Problem1 : Problem1.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Clean out your directory but keep executables with command "clean".  Gets rid
# of files you don't need anymore
clean:
	rm -f *.o *~ *% *# .#*

# Clean out your directory including executables with command "clean-all"
clean-all: clean
	rm -f Sudoku
