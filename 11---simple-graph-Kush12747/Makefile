CXXFLAG+=std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: simplegraph

simplegraph: graph.cc simplegraph.cc graph.h 
	g++ $(CXXFLAGS) -o simplegraph graph.cc simplegraph.cc

clean:
	rm -f simplegraph

world: clean all
