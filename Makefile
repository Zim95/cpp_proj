include src/Sources.mk

OBJECTS = $(SOURCES:.cpp=.o)

#CXX = g++
CXXFLAGS = -Wall -g -std=c++14 -O0
DEFINES = 
INCLUDE_DIRS = -Iinclude/
CPPFLAGS = $(DEFINES) $(INCLUDE_DIRS)
LDFLAGS = 
OUTPUT = bin/prog

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@

$(OUTPUT): $(OBJECTS)
	-mkdir bin
	$(CXX) $(LDFLAGS) $^ -o $@

.PHONY: build
build: $(OUTPUT)

.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(OUTPUT) bin
