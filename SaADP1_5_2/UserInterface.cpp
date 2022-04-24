#include <iostream>
#include <string>
#include "UserInterface.h"
#include "Node.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Build a perfectly balanced binary tree." << std::endl;
	std::cout << "2. Tree output in direct order ( | )." << std::endl;
	std::cout << "3. Tree output in symmetrical order ( << > )." << std::endl;
	std::cout << "4. Tree output in reverse - symmetrical order ( < >> )." << std::endl;
	std::cout << "5. Non-recursive tree traversal in symmetrical order." << std::endl;
	std::cout << "6. Exit." << std::endl;
	std::cout << std::endl;
}

int userInput()
{
	int option = 0;
	bool check = true;
	std::string optionInput;
	while (check)
	{
		try
		{
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl; std::cout << std::endl;
			check = true;
		}
	}
	return option;
}

void workWithUser(Node*& pRoot, Stack*& pHead)
{
	bool work = true;
	while (work)
	{
		std::cout << "   (0) - show menu." << std::endl;
		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput();
		switch (option)
		{
		case(ShowMenu):
		{
			printMainMenu();
			break;
		}
		case(BuildTree):
		{
			std::cout << "   Number of tree nodes" << std::endl;
			int n = userInput();
			if (n >= 0) { addNode(pRoot, n); break; }
			else std::cout << "   The number of nodes cannot be < 0." << std::endl;
			break;
		}
		case(DirectOrder):
		{
			showForward(pRoot, 0);
			break;
		}
		case(SymmetricalOrder):
		{
			showSymmetrical(pRoot, 0);
			break;
		}
		case(ReverseSymmetricalOrder):
		{
			showReverseSymmetrical(pRoot, 0);
			break;
		}
		case(NonRecursiveSymmetricalOrder):
		{
			showNonRecursiveSymmetrical(pRoot, pHead);
			break;
		}
		case(Exit):
		{
			work = false;
			break;
		}
		default:
			std::cout << "   There is no such menu item." << std::endl; std::cout << std::endl;
			break;
		}
	}
}