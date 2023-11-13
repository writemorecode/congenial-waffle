CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2 -ggdb3

serial_quicksort: src/serial_quicksort.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f serial_quicksort

