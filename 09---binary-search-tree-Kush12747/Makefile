CXXFLAG+=std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: bst

bst: bst.cc bst.h node.h btree.h binarysearchtree.h
	g++ $(CXXFLAGS) -o bst bst.cc

clean:
	rm -f bst

world: clean all
