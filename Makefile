all: RedBlack generateInput Makefile

RedBlack: RedBlackTree.cpp
	g++ -o RedBlackTree RedBlackTree.cpp

generateInput: generateInput.cpp
	g++ -o generateInput generateInput.cpp

clean:
	rm -rf RedBlackTree AVLTree SplayTree generateInput *.txt

.PHONY: clean all
