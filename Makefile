all: RedBlack generateInput Makefile SplayTree

RedBlack: RedBlackTree.cpp
	g++ -o RedBlackTree RedBlackTree.cpp

SplayTree: splay_tree.cc
	g++ -o SplayTree splay_tree.cc

generateInput: generateInput.cpp
	g++ -o generateInput generateInput.cpp

clean:
	rm -rf RedBlackTree AVLTree SplayTree generateInput *.txt

.PHONY: clean all
