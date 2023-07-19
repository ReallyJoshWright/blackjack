CXX = g++
CXXFLAGS = -std=c++20 -g -Wall
INCPATH = -I. -I../include
LIBS = -lpqxx -pq
ROOT = ../
INCLUDE = ../include
HEADERS = $(INCLUDE)/
OBJECTS = main.o
TARGET = blackjack

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET)
	mv $@ $(ROOT)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $<
.PHONY: clean
clean:
	rm -f $(ROOT)/$(TARGET) $(OBJECTS)
