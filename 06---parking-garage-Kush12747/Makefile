CXXFLAG+=std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: parking

parking: parking.cc garage.h car.h
	g++ $(CXXFLAGS) -o parking parking.cc

clean:
	rm -f parking

world: clean all
