TARGET = blackjack
SOURCEDIRS = src
INCLUDEDIRS = . ./include

CXX = g++
OPT = -O0
DEPFLAGS = -MP -MD
INCPATH = $(foreach D, $(INCLUDEDIRS), -I$(D))
CXXFLAGS = -std=c++20 -g -Wall -Wextra $(INCPATH) $(OPT) $(DEPFLAGS)

SOURCES = $(foreach D, $(SOURCEDIRS), $(wildcard $(D)/*.cpp))
OBJECTS = $(SOURCES:.cpp=.o)
DEPFILES = $(SOURCES:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY: clean distribute
clean:
	rm -rf $(TARGET) $(OBJECTS) $(DEPFILES) $(TARGET).tgz
distribute: clean
	tar -zcvf $(TARGET).tgz *

-include $(DEPFILES)
