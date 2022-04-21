#pragma once
#ifndef AVL
#define AVL
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "tree.h"
using std::string;
using std::vector;
using std::ofstream;
using std::cout;
using std::endl;
using std::max;

class avl: public tree
{
protected:
	void insert(treeNode*& p, int item);
	void deleteNode(treeNode*& p);
	int getHeight(treeNode* p);
	int getBalance(treeNode* p);
	void rotateRight(treeNode*& r);
	void rotateLeft(treeNode*& r);
	void balancing(treeNode*& p, int balance, int& item, int& count);

public:
	avl();
	~avl();
};

#endif

avl::avl()
{
	root = NULL;
	countSearch = 0;
	countDelete = 0;
	countInsert = 0;
	treeType = "AVL Tree";
}

void avl::insert(treeNode*& p, int item)
{
	if (p == NULL)
	{
		p = new treeNode;
		p->key = item;
		p->right = NULL;
		p->left = NULL;
		p->height = 1;
		return;
	}
	else if (item < p->key)
	{
		countInsert++;
		insert(p->left, item);
	}
	else
	{
		countInsert++;
		insert(p->right, item);
	}

	p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

	int balance = getBalance(p);

	if (balance < -1 || balance > 1)
	{

		balancing(p, balance, item, countInsert);
	}

}

void avl::balancing(treeNode*& p, int balance, int& item, int& count)
{
	if (balance > 1 && item < p->left->key)
	{
		if (root->left->left == p)
		{
			count++;
			rotateRight(p->left);
			rotateLeft(p);
		}
		else
		{
			count++;
			rotateLeft(p);
		}
	}

	if (balance < -1 && item > p->right->key)
	{
		if (root->right->right == p)
		{
			count++;
			rotateLeft(p->right);
			rotateRight(p);
		}
		else
		{
			count++;
			rotateRight(p);
		}
	}

	if (balance > 1 && item > p->left->key)
	{
		count++;
		rotateRight(p->left);
		rotateLeft(p);
	}

	if (balance < -1 && item < p->right->key)
	{
		count++;
		rotateLeft(p->right);
		rotateRight(p);
	}
}

void avl::rotateRight(treeNode*& r)
{
	if (r == NULL || r->right == NULL)
	{
		return;
	}
	treeNode* temp = r->right;
	r->right = temp->left;
	temp->left = r;
	r->height = max(getHeight(r->right), getHeight(r->left)) + 1;
	temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;
	r = temp;
}

void avl::rotateLeft(treeNode*& r)
{
	if (r == NULL || r->left == NULL)
	{
		return;
	}
	treeNode* temp = r->left;
	r->left = temp->right;
	temp->right = r;
	r->height = max(getHeight(r->right), getHeight(r->left)) + 1;
	temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;
	r = temp;
}

void avl::deleteNode(treeNode*& p)
{
	int item;
	treeNode* temp;

	temp = p;

	if (p->left == NULL)
	{
		p = p->right;
		delete temp;
	}
	else if (p->right == NULL)
	{
		p = p->left;
		delete temp;
	}
	else
	{
		treeNode* temp = p;
		getPredecessor(temp, item);
		p->key = temp->key;
		del(p->right, item);
	}

	if (p == NULL)
	{
		return;
	}

	p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

	int balance = getBalance(p);

	if (balance < -1 || balance > 1)
	{
		balancing(p, balance, item, countDelete);
	}

}

int avl::getBalance(treeNode* p)
{
	if (p == NULL)
	{
		return 0;
	}

	int balance = 0;
	balance = getHeight(p->left) - getHeight(p->right);
	return balance;
}

int avl::getHeight(treeNode* p)
{
	if (p == NULL)
	{
		return 0;
	}
	return p->height;
}

avl::~avl()
{
	destroy(root);
	root = NULL;
}