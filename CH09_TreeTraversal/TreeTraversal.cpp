#include <iostream>

using namespace std;

struct Node
{
	char Data;
	Node* LeftChild;
	Node* RightChild;

	Node(char NewData) : Data(NewData), LeftChild(nullptr), RightChild(nullptr) {}
};

class Tree
{
public:
	Node* Root;
	int NodeCount;
	
	Tree() : Root(nullptr), NodeCount(0) {}

	void AddNodeAt(char Parent, char Left, char Right)
	{
		if (Root == nullptr)
		{
			Node* NewParent = new Node(Parent);
			Root = NewParent;

			if (Left != '.')
				NewParent->LeftChild = new Node(Left);
			if (Right != '.')
				NewParent->RightChild = new Node(Right);
		}
		else
		{
			Node* Current = FindParent(Root, Parent);

			if (Left != '.')
				Current->LeftChild = new Node(Left);
			if (Right != '.')
				Current->RightChild = new Node(Right);
		}
	}

	Node* FindParent(Node* Target, char FindNode)
	{
		if (Target->Data == FindNode)
		{
			return Target;
		}
		else
		{
			if (Target->LeftChild != nullptr)
				return FindParent(Target->LeftChild, FindNode);
			if (Target->RightChild != nullptr)
				return FindParent(Target->RightChild, FindNode);
		}

		return nullptr;
	}

	void PrintPreorder(Node* Node)
	{
		if (Node == nullptr)
			return;

		cout << Node->Data;
		PrintPreorder(Node->LeftChild);
		PrintPreorder(Node->RightChild);
	}

	void PrintInorder(Node* Node)
	{
		if (Node == nullptr)
			return;

		PrintInorder(Node->LeftChild);
		cout << Node->Data;
		PrintInorder(Node->RightChild);
	}

	void PrintPostorder(Node* Node)
	{
		if (Node == nullptr)
			return;

		PrintPostorder(Node->LeftChild);
		PrintPostorder(Node->RightChild);
		cout << Node->Data;
	}
};

int main()
{
	int N;
	cin >> N;

	Tree* NewTree = new Tree;

	for (int i = 0; i < N; ++i)
	{
		char Parent, LeftChild, RightChild;
		cin >> Parent >> LeftChild >> RightChild;
		NewTree->AddNodeAt(Parent, LeftChild, RightChild);
	}

	NewTree->PrintPreorder(NewTree->Root);
	cout << '\n';
	NewTree->PrintInorder(NewTree->Root);
	cout << '\n';
	NewTree->PrintPostorder(NewTree->Root);

	return 0;
}