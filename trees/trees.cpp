#include "trees.h"
#include <iostream>
using namespace std;

Trees::Trees()
{
	m_proot = nullptr;

}

Trees::~Trees()
{

}

void Trees::inserthead(int value)
{
	Checker = m_proot;
	if (m_proot == nullptr)
	{
		m_proot = new CNode;
		m_proot->setData(value);
		m_proot->setleftNode(nullptr);
		m_proot->setright(nullptr);
		Checker = m_proot;
	}

}

void Trees::insert(int value)		//works
{
	Checker = m_proot;

	if (m_proot->getleftNode() == nullptr && value < m_proot->getData())	//fine
	{
		left = new CNode;
		left->setData(value);
		m_proot->setleftNode(left);
		Checker = left;
	}
	if (m_proot->getright() == nullptr && value > m_proot->getData())		//fine
	{
		right = new CNode;
		right->setData(value);
		m_proot->setright(right);
		Checker = right;
	}
	while (value != Checker->getData())
	{
		while (value < Checker->getData())
		{

			while (value < Checker->getData())
			{
				if (value < Checker->getData() && Checker->getleftNode() == nullptr)
				{
					left = new CNode;
					left->setData(value);
					Checker->setleftNode(left);
					Checker = left;
					break;
				}
				if (value > Checker->getData() && Checker->getright() == nullptr)
				{
					right = new CNode;
					right->setData(value);
					Checker->setright(right);
					Checker = right;
					break;
				}
				Checker = Checker->getleftNode();
			}
			while (value > Checker->getData())
			{
				if (value < Checker->getData() && Checker->getleftNode() == nullptr)
				{
					left = new CNode;
					left->setData(value);
					Checker->setleftNode(left);
					Checker = left;
					break;
				}
				if (value > Checker->getData() && Checker->getright() == nullptr)
				{
					right = new CNode;
					right->setData(value);
					Checker->setright(right);
					Checker = right;
					break;
				}

				Checker = Checker->getright();
			}

		}
		while (value > Checker->getData())
		{

			while (value < Checker->getData())
			{
				if (value < Checker->getData() && Checker->getleftNode() == nullptr)
				{
					left = new CNode;
					left->setData(value);
					Checker->setleftNode(left);
					Checker = left;
					break;
				}
				if (value > Checker->getData() && Checker->getright() == nullptr)
				{
					right = new CNode;
					right->setData(value);
					Checker->setright(right);
					Checker = right;
					break;
				}

				Checker = Checker->getleftNode();

			}
			while (value > Checker->getData())
			{
				if (value < Checker->getData() && Checker->getleftNode() == nullptr)
				{
					left = new CNode;
					left->setData(value);
					Checker->setleftNode(left);
					Checker = left;
					break;
				}
				if (value > Checker->getData() && Checker->getright() == nullptr)
				{
					right = new CNode;
					right->setData(value);
					Checker->setright(right);
					Checker = right;
					break;
				}

				Checker = Checker->getright();


			}
		}
	}
}


void Trees::Delete(int value)
{

	Checker = m_proot;
	CNode *prevnode = Checker;
	CNode *nextnode = Checker;
	Checker = checkersearch(value);
	prevnode = prevsearch(checkersearch(value));


	if (Checker->getleftNode() == nullptr && Checker->getright() == nullptr)  //if child nodes
	{
		if (prevnode->getleftNode() == Checker)
		{
			prevnode->setleftNode(nullptr);
			delete Checker;
			return;
		}
		if (prevnode->getright() == Checker)
		{
			prevnode->setright(nullptr);
			delete Checker;
			return;
		}


	}


	if (Checker->getleftNode() == nullptr || Checker->getright() == nullptr)
	{
		if (Checker->getleftNode() == nullptr)
		{
			prevnode->setright(Checker->getright());
			Checker->setright(nullptr);
			delete Checker;
			return;
		}

		if (Checker->getright() == nullptr)
		{
			prevnode->setleftNode(Checker->getleftNode());
			Checker->setleftNode(nullptr);
			delete Checker;
			return;
		}
	}
	if (Checker->getleftNode() != nullptr && Checker->getright() != nullptr) //when parent has 2 nodes
	{
		prevnode = Checker;
		Checker = Checker->getright();

		if (Checker->getleftNode() != nullptr)		//if checkers left node is not null, then it will def be the leftest nodes value swap with prev nodes
		{
			nextnode = Checker->getleftNode();//ok
			while (nextnode->getleftNode() != nullptr)
			{
				Checker = Checker->getleftNode();
				nextnode = nextnode->getleftNode();
				if (nextnode->getleftNode() == nullptr)
				{
					prevnode->setData(nextnode->getData());
					Checker->setleftNode(nullptr);

					delete nextnode;
					return;
				}

			}


		}
		if (Checker->getleftNode() == nullptr)      //if checkers left nodes is null means swap values with checker with prev node and delete checker
		{
			nextnode = Checker->getright();
			prevnode->setData(Checker->getData());
			prevnode->setright(nextnode);
			Checker->setright(nullptr);

			delete Checker;
			return;
		}


		if (Checker->getleftNode() == nullptr && Checker->getright() == nullptr)		//this is 3rd case and i think it works.
		{
			prevnode->setData(Checker->getData());
			prevnode->setright(nullptr);
			delete Checker;
			return;
		}
	}

}

bool Trees::Search(int value)
{
	CNode* previousnode = m_proot;
	Checker = m_proot;
	if (Checker->getData() == value)
	{
		std::cout << "true" << std::endl;
		return true;
	}

	while (value < Checker->getData())
	{

		while (value < Checker->getData())
		{
			if (value == Checker->getData())
			{
				std::cout << "true" << std::endl;
				return true;
			}

			if (value > Checker->getData())
			{
				Checker = Checker->getright();
			}
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{
				std::cout << "false" << std::endl;
				return false;
			}


		}
		while (value > Checker->getData())
		{
			if (value == Checker->getData())
			{
				std::cout << "true" << std::endl;
				return true;
			}
			if (value < Checker->getData())
			{
				Checker = Checker->getleftNode();
			}
			Checker = Checker->getright();
			if (Checker == nullptr)
			{
				std::cout << "false" << std::endl;
				return false;
			}

		}
		if (Checker->getData() == value)
		{
			std::cout << "true" << std::endl;
			return true;
		}
	}
	while (value > Checker->getData())
	{

		while (value < Checker->getData())
		{
			if (value == Checker->getData())
			{
				std::cout << "true" << std::endl;
				return true;
			}

			if (value > Checker->getData())
			{
				Checker = Checker->getright();
			}
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{
				std::cout << "false" << std::endl;
				return false;
			}

		}
		while (value > Checker->getData())
		{
			if (value == Checker->getData())
			{
				std::cout << "true" << std::endl;
				return true;
			}

			if (value < Checker->getData())
			{
				Checker = Checker->getleftNode();
			}
			Checker = Checker->getright();
			if (Checker == nullptr)
			{
				std::cout << "false" << std::endl;
				return false;
			}

		}
		if (Checker->getData() == value)
		{
			std::cout << "true" << std::endl;
			return true;
		}
	}


}

CNode* Trees::checkersearch(int value)
{
	CNode* previousnode = Checker;
	Checker = m_proot;
	if (Checker->getData() == value)
	{

		return Checker;
	}

	while (value < Checker->getData())
	{


		while (value < Checker->getData())
		{
			if (value == Checker->getData())
			{

				return Checker;
			}

			if (value > Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getright();
			}
			previousnode = Checker;
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{
				std::cout << "not found" << std::endl;
				return nullptr;
			}


		}
		while (value > Checker->getData())
		{
			if (value == Checker->getData())
			{

				return Checker;
			}
			if (value < Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getleftNode();
			}
			previousnode = Checker;
			Checker = Checker->getright();
			if (Checker == nullptr)
			{
				std::cout << "not found" << std::endl;
				return nullptr;
			}

		}
		if (Checker->getData() == value)
		{

			return Checker;
		}
	}
	while (value > Checker->getData())
	{

		while (value < Checker->getData())
		{
			if (value == Checker->getData())
			{

				return Checker;
			}

			if (value > Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getright();
			}
			previousnode = Checker;
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{
				std::cout << "not found" << std::endl;
				return nullptr;
			}

		}
		while (value > Checker->getData())
		{
			if (value == Checker->getData())
			{

				return Checker;
			}

			if (value < Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getleftNode();
			}
			previousnode = Checker;
			Checker = Checker->getright();
			if (Checker == nullptr)
			{
				std::cout << "not found" << std::endl;
				return nullptr;
			}

		}
		if (Checker->getData() == value)
		{

			return Checker;
		}
	}

}



void Trees::printpostorder()
{
	cout << endl;
	Printpostorder(m_proot);
}

void Trees::printinorder()
{
	cout << endl;
	Printinorder(m_proot);
}

void Trees::printpreorder()
{
	cout << endl;
	Printpreorder(m_proot);
}

void Trees::Printinorder(CNode * ptr) {

	if (m_proot->getright() != nullptr && m_proot->getleftNode() != nullptr)
	{
		if (ptr->getleftNode() != nullptr)
		{
			Printinorder(ptr->getleftNode());
		}
		std::cout << ptr->getData() << " ";
		if (ptr->getright() != nullptr)
		{
			Printinorder(ptr->getright());
		}
	}

	else
	{
		cout << "the tree is empty" << endl;
	}

}

void Trees::Printpostorder(CNode * ptr)
{

	if (m_proot->getright() != nullptr && m_proot->getleftNode() != nullptr)
	{
		if (ptr->getleftNode() != nullptr)
		{
			Printpostorder(ptr->getleftNode());
		}

		if (ptr->getright() != nullptr)
		{
			Printpostorder(ptr->getright());
		}
		std::cout << ptr->getData() << " ";
	}

	else
	{
		cout << "the tree is empty" << endl;
	}

}

void Trees::Printpreorder(CNode * ptr)
{

	if (m_proot->getright() != nullptr && m_proot->getleftNode() != nullptr)
	{
		std::cout << ptr->getData() << " ";
		if (ptr->getleftNode() != nullptr)
		{
			Printpreorder(ptr->getleftNode());
		}

		if (ptr->getright() != nullptr)
		{
			Printpreorder(ptr->getright());
		}

	}

	else
	{
		cout << "the tree is empty" << endl;
	}


}



CNode * Trees::prevsearch(CNode *ptr)
{
	CNode* previousnode = Checker;
	Checker = m_proot;
	if (Checker->getData() == ptr->getData())
	{
		return previousnode;
	}

	while (ptr->getData() < Checker->getData())
	{


		while (ptr->getData() < Checker->getData())
		{
			if (ptr->getData() == Checker->getData())
			{

				return previousnode;
			}

			if (ptr->getData() > Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getright();
			}
			previousnode = Checker;
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{

				return nullptr;
			}


		}
		while (ptr->getData() > Checker->getData())
		{
			if (ptr->getData() == Checker->getData())
			{

				return previousnode;
			}
			if (ptr->getData() < Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getleftNode();
			}
			previousnode = Checker;
			Checker = Checker->getright();
			if (Checker == nullptr)
			{

				return nullptr;
			}

		}
		if (Checker->getData() == ptr->getData())
		{

			return previousnode;
		}
	}
	while (ptr->getData() > Checker->getData())
	{

		while (ptr->getData() < Checker->getData())
		{
			if (ptr->getData() == Checker->getData())
			{

				return previousnode;
			}

			if (ptr->getData() > Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getright();
			}
			previousnode = Checker;
			Checker = Checker->getleftNode();
			if (Checker == nullptr)
			{

				return nullptr;
			}

		}
		while (ptr->getData() > Checker->getData())
		{
			if (ptr->getData() == Checker->getData())
			{

				return previousnode;
			}

			if (ptr->getData() < Checker->getData())
			{
				previousnode = Checker;
				Checker = Checker->getleftNode();
			}
			previousnode = Checker;
			Checker = Checker->getright();
			if (Checker == nullptr)
			{

				return nullptr;
			}

		}
		if (Checker->getData() == ptr->getData())
		{

			return previousnode;
		}
	}
}


