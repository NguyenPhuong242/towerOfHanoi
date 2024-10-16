# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O3

#Source files and object files
SRCS = main.cpp hanoi.cpp animation.cpp
OBJS = $(SRCS:.cpp=.o)

#Target
TARGET = hanoi

#Default rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

#Rule to clean the object files
clean:
	rm -f $(OBJS) $(TARGET)

#Dependencies
main.o: main.cpp hanoi.h animation.h
hanoi.o: hanoi.cpp hanoi.h animation.h
animation.o: animation.cpp animation.h