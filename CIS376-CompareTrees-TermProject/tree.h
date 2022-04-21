#pragma once
#ifndef TREE
#define TREE
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

struct treeNode
{
	int key;
	treeNode* right;
	treeNode* left;
	int height;
};

class tree
{
protected:
	treeNode* root;
	int countSearch;
	int countDelete;
	int countInsert;
	string treeType;

	virtual void insert(treeNode*& p, int item);
	virtual void print(treeNode* p, ofstream& f, int addSpaces);
	virtual void search(treeNode* p, int item, bool& status);
	virtual void del(treeNode*& p, int item);
	virtual void deleteNode(treeNode*& p);
	virtual void getPredecessor(treeNode* p, int& item);
	virtual void destroy(treeNode*& p);
	virtual int height(treeNode* p, int& h);

public:
	tree();
	virtual void insertNode(int item);
	virtual void printTree(ofstream& f);
	virtual void searchNode(int item, bool& status);
	virtual void deleteItem(int item);
	int findHeight();
	int getCountDeletes();
	int getCountInserts();
	int getCountSearches();
	~tree();
};



#endif

tree::tree()
{
	root = NULL;
	countSearch = 0;
	countDelete = 0;
	countInsert = 0;
	treeType = "Binary Search Tree";
}

int tree::getCountDeletes()
{
	return countDelete;
}

int tree::getCountInserts()
{
	return countInsert;
}

int tree::getCountSearches()
{
	return countSearch;
}

void tree::insertNode(int item)
{
	insert(root, item);
	countInsert++;
}

void tree::insert(treeNode*& p, int item)
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
}

void tree::searchNode(int item, bool& status)
{
	countSearch++;
	search(root, item, status);
}

void tree::search(treeNode* p, int item, bool& status)
{
	if (p == NULL)
	{
		status = false;
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
	}
}

void tree::deleteItem(int item)
{
	del(root, item);
}


void tree::del(treeNode*& p, int item)
{
	if (p == NULL)
	{
		return;
	}
	else if (item < p->key)
	{
		countDelete++;
		del(p->left, item);
	}
	else if (item > p->key)
	{
		countDelete++;
		del(p->right, item);
	}
	else
	{
		countDelete++;
		deleteNode(p);
		//return;
	}

}

void tree::deleteNode(treeNode*& p)
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

	return;
}

void tree::getPredecessor(treeNode* p, int& item)
{
	while (p != NULL && p->left != NULL)
	{
		countDelete++;
		p = p->left;
		//item = p->key;
	}
	item = p->key;
}


void tree::printTree(ofstream& f)
{
	f << "---------------------------------------------------------------" << endl;
	f << treeType << ':' << endl;
	print(root, f, 0);
	f << "---------------------------------------------------------------" << endl;
}

void tree::print(treeNode* p, ofstream& f, int addSpaces)
{
	
	if (root != NULL)
	{
		if (p->right != NULL)
		{
			print(p->right, f, addSpaces + 7);
		}

		for (int i = 0; i < addSpaces; i++)
		{
			f << " ";
		}

			f << p->key << endl;

		if (p->left != NULL)
		{
			print(p->left, f, addSpaces + 7);
		}
	}

}

int tree::findHeight()
{
	int ht = 0;
	height(root, ht);
	return (ht - 1);
}

int tree::height(treeNode* p, int& h)
{
	if (p == NULL)
	{
		return 0;
	}

	h = max(height(p->left, h), height(p->right, h)) + 1;

	return h;
}

void tree::destroy(treeNode*& p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
	}
}

tree::~tree()
{
	destroy(root);
	root = NULL;
}