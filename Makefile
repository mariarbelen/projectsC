CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2

SOURCES  := $(wildcard projects/*.cpp exercises/*.cpp)
BINARIES := $(patsubst %.cpp,bin/%,$(notdir $(SOURCES)))

vpath %.cpp projects exercises

.PHONY: all test clean

all: $(BINARIES)

bin/%: %.cpp | bin
	$(CXX) $(CXXFLAGS) -o $@ $<

bin:
	mkdir -p bin

test: all
	./tests/run_tests.sh

clean:
	rm -rf bin
