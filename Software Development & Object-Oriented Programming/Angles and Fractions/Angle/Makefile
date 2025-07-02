# Name- Arnav Sharma
# Student Id - 921870432
# Makefile for compiling the Angle class and the robot program

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = robot

# Source files
SRC = robot.cpp Angle.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Clean target for removing compiled files
clean:
	rm -f $(TARGET) $(OBJ)

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
