#pragma once
#include "Node.h"
enum userInterface
{
	ShowMenu,
	BuildTree,
	DirectOrder,
	SymmetricalOrder,
	ReverseSymmetricalOrder,
	NonRecursiveSymmetricalOrder,
	Exit,
	Continue = 1,
};

void printMainMenu();
int userInput();
void workWithUser(Node*& pRoot, Stack*& pHead);