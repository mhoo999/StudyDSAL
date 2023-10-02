#include "RedBlackTree.h"
#include <sstream>

RBTNode* Nil;

int main()
{
	RBTNode* Tree = nullptr;
	RBTNode* Node = nullptr;

	Nil = RBT_CreateNode(0);
	Nil->color = Color::BLACK;

	while (1)
	{
		int cmd = 0;
		int param = 0;
		string buffer;

		cout << "Enter command number :\n";
		cout << "(1) Create a node, (2) Remove a node, (3) Search a Node\n";
		cout << "(4) Display Tree (5) quit\n";
		cout << "command number: ";

		getline(cin, buffer);
		istringstream(buffer) >> cmd;

		if (cmd < 1 || cmd >5)
		{
			cout << "Invalid command number.\n";
			continue;
		}
		else if (cmd == 4)
		{
			RBT_PrintTree(Tree, 0, 0);
			cout << "\n";
			continue;
		}
		else if (cmd == 5)
			break;

		cout << "Enter parameter (1~200) :\n";

		getline(cin, buffer);
		istringstream(buffer) >> param;

		if (param < 1 || param > 200)
		{
			cout << "Invalid parameter." << param << "\n";
			continue;
		}

		switch (cmd)
		{
		case 1:
			RBT_InsertNode(Tree, RBT_CreateNode(param));
			break;
		case 2:
			Node = RBT_RemoveNode(Tree, param);

			if (Node == nullptr)
				cout << "Not found node to delete: " << param << "\n";
			else
				RBT_DestroyNode(Node);
			break;
		case3:
			Node = RBT_SearchNode(Tree, param);

			if (Node == nullptr)
				cout << "Not found node: " << param << "\n";
			else
				cout << "Found Node: " << Node->Data << "(Color: " << ((Node->color == Color::RED) ? "RED" : "BLACK") << ")\n";
			break;
		}

		cout << "\n";
	}

	RBT_DestroyTree(Tree);
	return 0;
}