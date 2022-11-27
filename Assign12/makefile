#
# PROGRAM:    Assignment 12
# AUTHOR:    Jacob Rudawski & Jacob Kurbis 
# LOGON ID:  (z1968579)     & (z1945650)
# DATE DUE:   11-30-2022
#

# Compiler variables
CXXFLAGS = -Wall -Werror -std=c++11
# Rule to link object code files to create executable file
all: assign12

assign12: assign12.o rectangle.o shape.o triangle.o circle.o
	g++ $(CXXFLAGS) -o assign12 $^
test: assign12.o rectangle.o shape.o circle.o triangle.o
	g++ $(CXXFLAGS) -o test $^

# Rules to compile source code files to object code
assign12.o: assign12.cpp circle.h shape.h rectangle.h triangle.h
shape.o: shape.cpp shape.h
circle.o: circle.cpp circle.h
rectangle.o: rectangle.cpp rectangle.h
trianle.o: triangle.cpp triangle.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 test *.o