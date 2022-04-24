#include <iostream>
#include "Node.h"
#include "UserInterface.h"

int main()
{
	Node* pRoot;
	Stack* pHead = nullptr;
	treeInit(pRoot);
	workWithUser(pRoot, pHead);
	treeClearMemory(pRoot);
	stackClearMemory(pHead);
}