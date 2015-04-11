all:
	g++ -o bst BSTNode.cpp BSTTree.cpp BSTmain.cpp
	g++ -o avl AVLNode.cpp AVLTree.cpp AVLmain.cpp
	g++ -o test testTrees.cpp AVLNode.cpp AVLTree.cpp BSTNode.cpp BSTTree.cpp
	
