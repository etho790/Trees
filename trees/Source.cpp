#include <iostream>
#include "trees.h"
using namespace std;

int main()
{
	Trees obj;
	obj.inserthead(50);
	obj.insert(60);
	obj.insert(90);
	obj.insert(55);
	obj.insert(58);
	obj.insert(57);
	obj.insert(59);
	obj.insert(53);
	obj.insert(54);
	obj.insert(52);
	obj.insert(40);
	obj.insert(30);
	obj.printinorder();		
	


	int g;
	cin >> g;
	return 0;
}