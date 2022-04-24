#include <iostream>
#include "Node.h"

void treeInit(Node*& pRoot) { pRoot = nullptr; }
bool treeIsEmpty(Node* pRoot) { return (pRoot == nullptr); }

void addNode(Node*& pCurrent, int n)
{
	Node* pTemporary;
	int nLeft, nRight;
	if (n == 0)  pCurrent = nullptr;								//���� ������ ��� ���������� ���, ��������� ������ ������
	else
	{
		nLeft = n / 2;												//���-�� ������ �����
		nRight = n - nLeft - 1;										//���-�� ������ ������
		pTemporary = new Node;										//�������� ����� ������
		pTemporary->data = rand() % 99;								//���������� ���-�� ����� ���� ��������� ������ � ��������� 0-99
		addNode(pTemporary->left, nLeft);							//���������� ������� ����� ���������
		addNode(pTemporary->right, nRight);							//���������� ������� ������ ���������
		pCurrent = pTemporary;										//���������� ����� ���������� �����
	}
}

void showForward(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { std::cout << "     "; }	//��� ������ ���-�� level � ����� for ��������� �����-� �������
		std::cout << pCurrent->data << std::endl; level++;			//����� �� ������� ���-�� ����� ���� � ���������� ������ �� 1
		showForward(pCurrent->left, level);							//����������� ����� ������� ��� ������ ���������
		showForward(pCurrent->right, level);						//����������� ����� ������� ��� ������� ���������
	}
}

void showSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showSymmetrical(pCurrent->left, level);
		for (int i = 0; i < level - 1; i++) { std::cout << "     "; }
		std::cout << pCurrent->data << std::endl;
		showSymmetrical(pCurrent->right, level);
	}
}

void showReverseSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showReverseSymmetrical(pCurrent->right, level);
		for (int i = 0; i < level - 1; i++) { std::cout << "     "; }
		std::cout << pCurrent->data << std::endl;
		showReverseSymmetrical(pCurrent->left, level);
	}
}

void showNonRecursiveSymmetrical(Node*& pCurrentNode, Stack*& pHead)
{
	Node* pCurrent = pCurrentNode;
	int level = 0;
	bool stop = false;
	while (!stop)
	{
		while (pCurrent != nullptr)										//���� �� ���������� ������ �������
		{
			level++;
			stackAddItem(pHead, pCurrent, level);						//��������� ������� � ����
			pCurrent = pCurrent->left;									//������� � ������ �������
		}
		if (stackIsEmpty(pHead)) { stop = true; }						//���� ���� ������, �� ������������� �������� ����
		else
		{
			pCurrent = pHead->pNode;									//��������� �� ����� ������� ������� � � �������
			level = pHead->level;
			for (int i = 0; i < level - 1; i++) { std::cout << "     "; }
			std::cout << pCurrent->data << std::endl;					//������� ����������
			pCurrent = pCurrent->right;									//��������� � ������� �������
			stackDeleteItem(pHead);										//������� ������� �����
		}
	}
}

void treeClearMemory(Node*& pCurrent)
{
	if (pCurrent != nullptr)
	{
		treeClearMemory(pCurrent->left);								//������� ������ ��� ������ ��������� ������
		treeClearMemory(pCurrent->right);
		delete pCurrent;
	}
}


bool stackIsEmpty(Stack* pHead)
{
	return pHead == nullptr;
}

void stackAddItem(Stack*& pHead, Node*& pCurrentNode, int level)
{
	Stack* pCurrentStack = new Stack;
	pCurrentStack->level = level;
	pCurrentStack->pNode = pCurrentNode;
	pCurrentStack->previous = pHead;
	pHead = pCurrentStack;
}

void stackDeleteItem(Stack*& pHead)
{
	Stack* pTemporary = pHead;
	pHead = pHead->previous;
	delete pTemporary;
	pTemporary = nullptr;
}

void stackClearMemory(Stack*& pHead)
{
	Stack* pTemporary = pHead;
	while (pTemporary != NULL) { stackDeleteItem(pTemporary); }
	pHead = nullptr;
}