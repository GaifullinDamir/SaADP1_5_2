#pragma once

struct Node
{
	int data;
	Node* left, * right;
};

struct Stack
{
	Node* pNode;
	int level;
	Stack* previous;
};

/*Node*/
void treeInit(Node*& pRoot);
bool treeIsEmpty(Node* pRoot);
void addNode(Node*& pRoot, int n);
void showForward(Node* pRoot, int level);
void showSymmetrical(Node* pRoot, int level);
void showReverseSymmetrical(Node* pCurrent, int level);
void showNonRecursiveSymmetrical(Node*& pCurrentNode, Stack*& pHead);
void treeClearMemory(Node*& pCurrent);

/*Stack*/
void stackAddItem(Stack*& pHead, Node*& pCurrentNode, int level);
bool stackIsEmpty(Stack* pHead);
void stackDeleteItem(Stack*& pHead);
void stackClearMemory(Stack*& pHead);