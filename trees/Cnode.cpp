#include <iostream>

#include "CNode.h" 


CNode::CNode()
{
	data = 0;
	leftNode = nullptr;
	rightnode = nullptr;
	prevnode = nullptr;
}

void CNode::setData(int iData)
{
	data = iData;


}
int CNode::getData() const
{
	return (data);

}

void CNode::setleftNode(CNode * left)
{
	this->leftNode = left;
}

CNode * CNode::getleftNode() const
{
	return (leftNode);
}

void CNode::setright(CNode * right)
{
	this->rightnode = right;
}

CNode * CNode::getright()
{
	return rightnode;
}

