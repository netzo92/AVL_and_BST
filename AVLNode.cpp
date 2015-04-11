#include <stdio.h>
#include <stdlib.h>
#include "AVLNode.h"

AVLNode::AVLNode(int value)
{
	val = value;
	height = 0;
	right = NULL;
	left = NULL;
}

int AVLNode::balanceFactor()
{
	int rightV;
	int leftV;
	if(right == NULL)
		rightV = -1;
	else
		rightV = right->height;
	
	if(left == NULL)
		leftV = -1;
	else	
		leftV = left->height;
	
	return leftV-rightV;


}

int getHeight(AVLNode *n)
{
	if(n == NULL)
		return -1;
	
	return n->height;
}
void updateHeight(AVLNode *n)
{
	int rV = -1; 
	int lV = -1;
	
	if(n->right != NULL)
		rV = n->right->height;
	if(n->left != NULL)
		lV = n->left->height;

	if(rV > lV)
		n->height = rV + 1;
	else
		n->height = lV + 1;
}

void rotateLeft(AVLNode *n)
{
	AVLNode *b1,*b2,*b3;
	int hold, tmp;

	b1 = n->left;
	b2 = n->right->left;
	b3 = n->right->right;
	
	tmp = n->val;
	hold = n->right->val;
	delete n->right;

	n->val = hold;
	n->left = new AVLNode(tmp);
	n->right = b3;
	n->left->left = b1;
	n->left->right = b2;

	updateHeight(n);
	updateHeight(n->left);
}

void rotateRight(AVLNode *n)
{
	AVLNode *b1,*b2,*b3;
	int hold, tmp;
	
	b3 = n->right;
	b2 = n->left->right;
	b1 = n->left->left;

	tmp = n->val;
	hold = n->left->val;
	delete n->left;
	
	n->val = hold;
	n->right = new AVLNode(tmp);
	n->left = b1;
	n->right->left = b2;
	n->right->right = b3;

	updateHeight(n);
	updateHeight(n->right);
}

void fixNode(AVLNode *n)
{
	if(n->balanceFactor() > 1)
	{
		if(getHeight(n->left->left) < getHeight(n->left->right))
		{
			rotateLeft(n->left);
		}
		rotateRight(n);	
	}
	
	else if(n->balanceFactor() < -1)
	{
		if(getHeight(n->right->left) > getHeight(n->right->right))
			rotateRight(n->right);
		rotateLeft(n);
	}
}

