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
	treeNode* twin;
	int numOfTwin;
	int height;
};

class tree
{
protected:
	/*
	struct treeNode
	{
		int key;
		treeNode* right;
		treeNode* left;
		treeNode* twin;
		int numOfTwin;
	};
	*/

	treeNode* root;
	int countSearch;
	int countDelete;
	int countInsert;
	//const string filename = "TreeLogFile.txt";
	string treeType;

	virtual void insert(treeNode*& p, int item);
	virtual void print(treeNode* p, ofstream& f, int addSpaces);//ofstream& f, int addSpaces);
	virtual void search(treeNode* p, int item, bool& status);
	virtual void del(treeNode*& p, int item);
	virtual void deleteNode(treeNode*& p);
	virtual void getPredecessor(treeNode* p, int& item);
	virtual void destroy(treeNode*& p);
	virtual int height(treeNode* p, int& h);

public:
	tree();
	virtual void insertNode(int item);//, ofstream& f);
	virtual void printTree(ofstream& f);
	virtual void searchNode(int item, bool& status);// , ofstream& f);
	virtual void deleteItem(int item);// , ofstream& f);
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

/*
Desc: getter for count inserts
Pre-condition : none
Post-condition : returns count inserts
*/
int tree::getCountInserts()
{
	return countInsert;
}

/*
Desc: getter for count searches
Pre-condition : none
Post-condition : returns count searches
*/
int tree::getCountSearches()
{
	return countSearch;
}

/*
Desc: insert node function that calls internal insert function
Pre-condition : integer
Post-condition : none
*/
void tree::insertNode(int item)//, ofstream& f)
{
	insert(root, item);
	countInsert++;
}

/*
Desc: inserts a node at a leaf point
Pre-condition : treeNode pointer, integer
Post-condition : none
*/
void tree::insert(treeNode*& p, int item)
{
	if (p == NULL)
	{
		p = new treeNode;
		p->key = item;
		//p->numOfTwin = 1;
		//p->twin = NULL;
		p->right = NULL;
		p->left = NULL;
		return;
	}
	/*
	else if (item == p->key)
	{
		//p->twin = new treeNode;
		p->numOfTwin++;
		countInsert++;
		insert(p->twin, item);
		return;
	}
	*/
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

/*
Desc: search function that calls internal search function
Pre-condition : integer, boolean
Post-condition : none
*/
void tree::searchNode(int item, bool& status)//, ofstream& f)
{
	search(root, item, status);
	countSearch++;
}

/*
Desc: searches for a node
Pre-condition : treeNode pointer, integer, boolean
Post-condition : none
*/
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
		item = p->key;
		status = true;
	}
}

/*
Desc: delete function that calls internal search for delete function
Pre-condition :integer
Post-condition : none
*/
void tree::deleteItem(int item)//, ofstream& f)
{
	del(root, item);
	countDelete++;
}

/*
Desc: searches for where to delete
Pre-condition : treeNode pointer, integer
Post-condition : none
*/
void tree::del(treeNode*& p, int item)
{
	if (p == NULL)
	{
		//cout << item << " does not exist in the tree" << endl;
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
	/*
	else if (item == p->key && p->numOfTwin > 1)
	{
		p->numOfTwin--;
		//treeNode* prev = p;
		//treeNode* temp = p->twin;
		//while (temp != NULL)
		//{
		//	prev = temp;
		//	temp = p->twin;
		//}
		//prev->twin = temp->twin;
		//delete temp;
	}
	*/
	else
	{
		deleteNode(p);
		//return;
	}

}

/*
Desc: deletes the node
Pre-condition : treeNode pointer
Post-condition : none
*/
void tree::deleteNode(treeNode*& p)
{
	int item;
	treeNode* temp;

	temp = p;

	//if (p->twin !=  NULL)
	//{
	//	p->numOfTwin--;
		//while (p->twin != NULL)
		//{
		//	temp = p->twin;
		//}
		//delete temp;
	//}

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
		getPredecessor(temp, item); // p->right
		p->key = temp->key;
		//p->twin = temp->twin;
		del(p->right, item);
	}

	return;
	//temp = NULL;
}

/*
Desc: finds the smallest in the tree given
Pre-condition : treeNode pointer, integer
Post-condition : none
*/
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
	//f.open(filename, std::ios_base::app);

	f << "---------------------------------------------------------------" << endl;
	f << treeType << ':' << endl;
	print(root, f, 0);
	f << "---------------------------------------------------------------" << endl;
}

/*
Desc: prints 
Pre-condition :treeNode pointer, ofstream, integer
Post-condition : none
*/
void tree::print(treeNode* p, ofstream& f, int addSpaces)//ofstream& f, int addSpaces)
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
			//f << " ";
			cout << " ";
		}
		/*
		if (p->twin != NULL && p->numOfTwin > 1)
		{
			f << p->key << "(" << p->numOfTwin << ")" << endl;
		}
		else
		{
<<<<<<< HEAD
			f << p->key << endl;
		}
=======
		*/
			f << p->key << endl;
		//}

		if (p->left != NULL)
		{
			//print(p->left, addSpaces + 7);
			print(p->left, f, addSpaces + 7);

		}
	}

}

/*
Desc: calls internal height function to find the height of the tree
Pre-condition :none
Post-condition :integer
*/
int tree::findHeight()
{
	int ht = 0;
	height(root, ht);
	return (ht - 1);
}

/*
Desc: finds the height of the tree given
Pre-condition :treeNode pointer, integer
Post-condition : integer
*/
int tree::height(treeNode* p, int& h)
{
	if (p == NULL)
	{
		return 0;
	}

	h = max(height(p->left, h), height(p->right, h)) + 1;

	return h;
}

/*
Desc: destroys the tree
Pre-condition :treeNode pointer
Post-condition : none
*/
void tree::destroy(treeNode*& p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		//p = p->twin;
		delete p;
	}
}

tree::~tree()
{
	destroy(root);
	root = NULL;
}