CXX = g++
CXXFLAGS = -std=c++20 -g -Wall
INCPATH = -I. -I../include
LIBS = -lpqxx -pq
ROOT = ../
INCLUDE = ../include
HEADERS = $(INCLUDE)/blackjack.h
OBJECTS = main.o blackjack.o
TARGET = blackjack

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET)
	mv $@ $(ROOT)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $<
blackjack.o: blackjack.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $<
.PHONY: clean
clean:
	rm -f $(ROOT)/$(TARGET) $(OBJECTS)
