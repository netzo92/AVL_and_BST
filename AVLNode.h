#ifndef AVLNODE_H
#define AVLNODE_H

using namespace std;
class AVLNode
{

	public:
		int val;
		int height;
		AVLNode *left;
		AVLNode *right;

		AVLNode(int );
		int balanceFactor(void );
};

int getHeight(AVLNode *);
void updateHeight(AVLNode *);
void fixNode(AVLNode *);
#endif
