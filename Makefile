CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2 -ggdb3

qs: qs.cpp
	$(CXX) $(CXXFLAGS) qs.cpp -o qs

clean:
	rm -f qs

