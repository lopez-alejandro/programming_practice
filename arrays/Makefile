# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++-4.8
    else
        CC=g++
    endif
endif

# compiler flags for debug
CPPFLAGS=-std=c++11 -Wall -g -DDEBUG

all: p6_1

p6_1.o: p6_1.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

p6_1: p6_1.o
	$(CC) $^ -o $@ $(CPPFLAGS)

.PHONY: clean

.PHONY: all

clean:
	rm -rf *o p6_1

