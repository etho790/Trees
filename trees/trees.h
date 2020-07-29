#ifndef _trees_H__
#define _trees_H__

#include "CNode.h"

class Trees {
private:
	CNode *m_proot;
	CNode *Checker;
	CNode * left;
	CNode * right;
	void Printinorder(CNode* ptr);
	void Printpostorder(CNode* ptr);
	void Printpreorder(CNode* ptr);
	CNode* prevsearch(CNode *ptr);

public:
	Trees();
	~Trees();
	void inserthead(int value);
	void insert(int value);
	
	void Delete(int value);
	bool Search(int value);
	CNode* checkersearch(int value);
	
	void printpostorder();
	void printinorder();
	void printpreorder();
};
#endif