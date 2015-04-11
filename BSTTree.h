#ifndef BSTTREE_H
#define BSTTREE_H

#include <stdlib.h>
#include <stdio.h>

#include "BSTNode.h"

class BSTTree {
	BSTNode *root;
	
	public:
		BSTTree();
		bool deleteElement(int );
		bool deleteElementh(int ,BSTNode *);
		int deleteSuccessor(BSTNode *);
		int deleteSuccessorh(BSTNode *);
		
		bool lookupElement(int );
		void printTree(void );	
		bool insertElement(int );
		bool insertElementh(int ,BSTNode *);
};
#endif
