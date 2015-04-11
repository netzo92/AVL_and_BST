#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdlib.h>
#include <stdio.h>

#include "AVLNode.h"

class AVLTree {
	AVLNode *root;
	
	public:
		AVLTree();
		bool deleteElement(int );
		bool deleteElementh(int , AVLNode *);
		int deleteSuccessor(AVLNode *);
		int deleteSuccessorh(AVLNode *);
		bool lookupElement(int );
		void printTree(void );	
		bool insertElement(int );
		bool insertElementh(int ,AVLNode *);
		bool checkAVL(void );
		bool checkAVL(AVLNode * );
};
#endif
