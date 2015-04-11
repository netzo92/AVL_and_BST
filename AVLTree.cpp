#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"
#include <string.h>
#include <iostream>
using namespace std;
AVLTree::AVLTree()
{
	root = NULL;
}



bool AVLTree::insertElement(int value)
{	
	if(root == NULL)
	{
		root = new AVLNode(value);	
		return true;	
	}
	else
	{
		if(insertElementh(value,root))
		{
			return true;
		}
		else 
			return false;
	}
}

bool AVLTree::insertElementh(int value, AVLNode *n)
{	 
	bool returnVal;
	if(n->val == value)
		returnVal = false;
	else if(n->val < value)
	{
		if(n->right != NULL)
		{
			returnVal = insertElementh(value, n->right);
		}
		else
		{
			n->right = new AVLNode(value);
			returnVal = true;
		}
	}
	else if(n->val > value)
	{
		if(n->left != NULL)
		{
			returnVal = insertElementh(value,n->left);
		}
		else
		{
			n->left = new AVLNode(value);	
			returnVal = true;
		}	
	}

	if(returnVal == true)
	{
		updateHeight(n);
		fixNode(n);
	}
	return returnVal;
}

bool AVLTree::lookupElement(int value)
{
	AVLNode *n = root;


	while(n != NULL)
	{

		if(n->val > value)
		{
			n = n->left;
		}

		else if(n->val < value)
		{

			n = n->right;
		}
	
		else if(n->val == value)
		{
			return true;

		}
	}
	return false;

}




void preOrder(AVLNode *n, string *str)
{
	if(n == NULL)
		return;

	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%d", n->val);
	
	str->append(buffer);
	str->append(" ");
	preOrder(n->left, str);
	preOrder(n->right, str);	
}

void inOrder(AVLNode *n, string *str)
{
	if(n == NULL)
		return;	


	inOrder(n->left,str);
        char buffer[32];
	snprintf(buffer,sizeof(buffer), "%d",n->val);
	str->append(buffer);
	str->append(" ");
	inOrder(n->right,str);

}

void AVLTree::printTree()
{
	
	string out;
	preOrder(root,&out);
	if(out.size() != 1)
		out = out.substr(0,out.size()-1);
	out.append("\n");
	inOrder(root,&out);
	out = out.substr(0,out.size()-1);
	out.append("\n");
	cout <<out;
}


bool AVLTree::deleteElement(int value)
{
	bool retVal;
	if(root == NULL)
		retVal = false;
	else if(root->val == value)
	{
		retVal = true;
		if(root->right == NULL && root->left == NULL)
		{	
			delete root;
			root = NULL;
		}
		else if((root->right == NULL) != (root->left == NULL))
		{
			if(root->right != NULL)
			{
				root = root->right;		
			}	
			else if(root->left != NULL)
			{
				root = root->left;
			}
		}	
		else if(root->right != NULL && root->left != NULL)
		{
			root->val = deleteSuccessor(root);
		}
		if(root != NULL)
		{
			updateHeight(root);
			fixNode(root);
		}
	}
	else 
	retVal = deleteElementh(value,root);
	return retVal;
}

bool AVLTree::deleteElementh(int value, AVLNode *n)
{
	bool retVal;
	if(n == NULL)
		retVal = false;
	else if(n->val < value)
	{
		if(n->right == NULL)
			retVal = false;
		else if(n->right->val != value)
			retVal = deleteElementh(value,n->right);
		else if(n->right->val == value)
		{
			retVal = true;
			if(n->right->left == NULL && n->right->right == NULL)
			{
				delete n->right;
				n->right = NULL;
			}
			else if((n->right->left == NULL) != (n->right->right == NULL))
			{
				AVLNode *tmp = n->right;
				if(n->right->right != NULL)
					n->right = n->right->right;
				else if(n->right->left != NULL)
					n->right = n->right->left;
				delete tmp;
			}
			else if(n->right->right != NULL && n->right->left != NULL)
			{
				n->right->val = deleteSuccessor(n->right);
				fixNode(n->right);
			}
		}
	}
	else if(n->val > value)
	{
		if(n->left == NULL)
			retVal = false;
		else if(n->left->val != value)
			retVal = deleteElementh(value,n->left);
		else if(n->left->val == value)
		{	
			retVal = true;
			if(n->left->left == NULL && n->left->right == NULL)
			{
				delete n->left;
				n->left = NULL;	
			}
			else if((n->left->left == NULL) !=  (n->left->right == NULL))
			{
				AVLNode *tmp = n->left;
				if(n->left->left != NULL)
					n->left = n->left->left;
				else if(n->left->right != NULL)
					n->left = n->left->right;
				delete tmp;
			}
			else if(n->left->right != NULL && n->left->left != NULL)
			{
				n->left->val = deleteSuccessor(n->left);
				fixNode(n->left);
			}
		}	
	}
	updateHeight(n);
	fixNode(n);

	return retVal;

}
int AVLTree::deleteSuccessor(AVLNode *n)
{
	int tmp;
	AVLNode *store;
	if(n->right->left == NULL)
	{
		tmp = n->right->val;
		store = n->right;
		n->right = n->right->right;
		delete store;
	}
	else
	tmp = deleteSuccessorh(n->right);
	updateHeight(n);
	 //fixNode(n);
	return tmp;
}

int AVLTree::deleteSuccessorh(AVLNode *n)
{
	int tmp;
	AVLNode *store;
	if(n->left->left == NULL)
	{
		tmp = n->left->val;
		store = n->left;
		n->left = n->left->right;
		delete store;
	}
	else
	{
		tmp = deleteSuccessorh(n->left);
	}


	updateHeight(n);
	fixNode(n);
	return tmp;
}

bool AVLTree::checkAVL()
{
	return checkAVL(root);	
}


bool AVLTree::checkAVL(AVLNode *n)
{
	bool rVal, lVal;
	if(n == NULL)
		return true;

		
	if(n->balanceFactor() < -1 || n->balanceFactor() > 1)
	{

		return false;
	}
	if(n->right != NULL)
	{
		if(n->right->val < n->val)
			return false;
	}
	rVal = checkAVL(n->right);
	
	if(n->left != NULL)
	{
		if(n->left->val > n->val)
			return false;
	}
	lVal = checkAVL(n->left);


	return (lVal && rVal);

}



