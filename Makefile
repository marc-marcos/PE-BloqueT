all: RedBlack AVL Splay generateInput

RedBlack: RedBlackTree.cpp
	g++ -o RedBlackTree RedBlackTree.cpp

AVL:

Splay:

generateInput:
	g++ -o generateInput generateInput.cpp

clean:
	rm -rf RedBlackTree generateInput *.txt
