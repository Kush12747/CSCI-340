CXXFLAG+=std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: hash

hash: hashmain.cc htable.cc htable.h hashmain.h entry.h
	g++ $(CXXFLAGS) -o hash htable.cc hashmain.cc

clean:
	rm -f hash

world: clean all
