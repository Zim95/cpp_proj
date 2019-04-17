INCLUDE = -Iinclude
SOURCES = src/main.cpp
OUTPUT = bin/main.out
build: include/main.h
	mkdir bin
	g++ $(INCLUDE) $(SOURCES) -o $(OUTPUT)

clean:
	

