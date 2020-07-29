#ifndef _NODE_H__
#define _NODE_H__

class CNode {
private:
	int data;
	CNode *leftNode;
	CNode *rightnode;
	CNode *prevnode;

public:
	CNode();
	void setData(int iData);
	int getData() const;
	void setleftNode(CNode *left);
	CNode* getleftNode() const;
	void setright(CNode* right);
	CNode* getright();
	
};

#endif
