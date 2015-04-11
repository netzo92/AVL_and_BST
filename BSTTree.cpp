#include <stdio.h>
#include <stdlib.h>
#include "BSTTree.h"
#include <string.h>
#include <iostream>
using namespace std;
BSTTree::BSTTree()
{
	root = NULL;
}


bool BSTTree::insertElement(int value)
{
	if(root == NULL)
	{
		root = new BSTNode(value);	
		return true;	
	}
	else
	{
		return insertElementh(value,root);
	}
}
bool BSTTree::insertElementh(int value, BSTNode *n)
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
			n->right = new BSTNode(value);
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
			n->left = new BSTNode(value);	
			returnVal = true;
		}	
	}
	return returnVal;
}


bool BSTTree::lookupElement(int value)
{
	BSTNode *n = root;


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




void preOrder(BSTNode *n, string *str)
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

void inOrder(BSTNode *n, string *str)
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

void BSTTree::printTree()
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


bool BSTTree::deleteElement(int value)
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
	}
	else 
	retVal = deleteElementh(value,root);
	return retVal;
}


bool BSTTree::deleteElementh(int value, BSTNode *n)
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
				BSTNode *tmp = n->right;
				if(n->right->right != NULL)
					n->right = n->right->right;
				else if(n->right->left != NULL)
					n->right = n->right->left;
				delete tmp;
			}
			else if(n->right->right != NULL && n->right->left != NULL)
			{
				n->right->val = deleteSuccessor(n->right);
	
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
				BSTNode *tmp = n->left;
				if(n->left->left != NULL)
					n->left = n->left->left;
				else if(n->left->right != NULL)
					n->left = n->left->right;
				delete tmp;
			}
			else if(n->left->right != NULL && n->left->left != NULL)
			{
				n->left->val = deleteSuccessor(n->left);
			}
		}	
	}

	return retVal;

}

int BSTTree::deleteSuccessor(BSTNode *n)
{
	int tmp;
	BSTNode *store;
	if(n->right->left == NULL)
	{
		tmp = n->right->val;
		store = n->right;
		n->right = n->right->right;
		delete store;
	}
	else
	tmp = deleteSuccessorh(n->right);
	return tmp;
}

int BSTTree::deleteSuccessorh(BSTNode *n)
{
	int tmp;
	BSTNode *store;
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


	return tmp;
}
