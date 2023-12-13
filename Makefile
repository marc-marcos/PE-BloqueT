all: RedBlack generateInput Makefile SplayTree AVL

RedBlack: RedBlackTree.cc
	g++ -o RedBlackTree RedBlackTree.cc

SplayTree: splay_tree.cc
	g++ -o SplayTree splay_tree.cc

generateInput: generateInput.cpp
	g++ -o generateInput generateInput.cpp

AVL: AVL.cc
	g++ -o AVL AVL.cc

clean:
	rm -rf RedBlackTree SplayTree generateInput *.txt AVL 

.PHONY: clean all
