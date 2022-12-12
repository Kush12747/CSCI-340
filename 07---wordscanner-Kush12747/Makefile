CXXFLAG+=std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: wordscanner

wordscanner: wordscanner.cc
	g++ $(CXXFLAGS) -o wordscanner wordscanner.cc

clean:
	rm -f wordscanner

world: clean all
