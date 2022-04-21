#pragma once
#ifndef SPLAY
#define SPLAY
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using std::string;
using std::vector;
using std::ofstream;
using std::cout;
using std::endl;
using std::max;

class splay: public tree
{
private:
	void insert(treeNode*& p, int item);
	void search(treeNode*& p, int item, bool& status);
	void deleteNode(treeNode*& p);
	void zig(treeNode*& r);
	void zag(treeNode*& r);
	void splaying(treeNode*& p, int item, int& count);

public:
	splay();
	void deleteItem(int item);
	~splay();
};

#endif

splay::splay()
{
	root = NULL;
	countSearch = 0;
	countDelete = 0;
	countInsert = 0;
	treeType = "Splay Tree";
}

void splay::splaying(treeNode*& p, int item, int& count)
{
	if (p == NULL || p->key == item)
	{
		return;
	}

	if (item < p->key)
	{

		if (p->left == NULL)
		{
			return;
		}

		if (p->left->left != NULL && p->left->left->key == item)
		{
			count++;
			splaying(p->left->left, item, count);
			zig(p);
			zig(p);
		}

		else if (p->left->right != NULL && item > p->left->key)
		{
			count++;
			zag(p->left);
			zig(p);
		}

		else if (root->left != NULL && root->left->key == item)
		{
			count++;
			zig(p);
		}

		else
		{
			return;
		}

	}
	else
	{
		if (p->right == NULL)
		{
			return;
		}

		if (p->right->left != NULL && item < p->right->key)
		{
			count++;
			zag(p->left);
			zig(p);
		}

		else if (p->right->right != NULL && p->right->right->key == item)
		{
			count++;
			splaying(p->right->right, item, count);
			zag(p);
			zag(p);
		}

		else if (root->right != NULL && root->right->key == item)
		{
			count++;
			zag(p);
		}

		else
		{
			return;
		}
	}
}

void splay::insert(treeNode*& p, int item)
{
	if (p == NULL)
	{
		p = new treeNode;
		p->key = item;
		p->right = NULL;
		p->left = NULL;
		countInsert++;
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

	splaying(p, item, countInsert);
}

void splay::zag(treeNode*& r)
{
	if (r == NULL || r->right == NULL)
	{
		return;
	}
	treeNode* temp = r->right;
	r->right = temp->left;
	temp->left = r;
	r = temp;
}

void splay::zig(treeNode*& r)
{
	if (r == NULL || r->left == NULL)
	{
		return;
	}
	treeNode* temp = r->left;
	r->left = temp->right;
	temp->right = r;
	r = temp;
}

void splay::search(treeNode*& p, int item, bool& status)
{
	if (p == NULL)
	{
		status = false;
		return;
	}
	else if (item < p->key)
	{
		countSearch++;
		search(p->left, item, status);
	}
	else if (item > p->key)
	{
		countSearch++;
		search(p->right, item, status);
	}
	else
	{
		countSearch++;
		item = p->key;
		status = true;
		return;
	}

	splaying(p, item, countSearch);
}

void splay::deleteItem(int item)
{
	splaying(root, item, countDelete);
	del(root, item);
}

void splay::deleteNode(treeNode*& p)
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

}

splay::~splay()
{
	destroy(root);
	root = NULL;
}