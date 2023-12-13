all: RedBlack generateInput Makefile AVL

RedBlack: RedBlackTree.cc
	g++ -o RedBlackTree RedBlackTree.cc

generateInput: generateInput.cpp
	g++ -o generateInput generateInput.cpp

AVL: AVL.cc
	g++ -o AVL AVL.cc

clean:
	rm -rf RedBlackTree SplayTree generateInput *.txt AVL 

.PHONY: clean all
