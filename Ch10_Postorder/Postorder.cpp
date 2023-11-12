#include <iostream>

using namespace std;

struct Node
{
	string Data;
};

class ArrayStack
{
public:
	int Top;
	Node* Nodes;

	ArrayStack() : Top(-1), Nodes(new Node[100]) {}

	void MakeInorder(int order, char Data)
	{
		if (Data == '+' || Data == '-' || Data == '*' || Data == '/')
		{
			OrderCalculate(PopStack() + PopStack());
			PushStack(order, Data);
		}
		else
		{
			PushStack(order, Data);
		}
	}

	void PushStack(int order, char Data)
	{
		Node* NewNode = new Node;

		NewNode->Data = Data;
		Nodes[order] = *NewNode;
	}

	
};

int main()
{
	ArrayStack* Stack = new ArrayStack;

	int N;
	cin >> N;

	string Postorder;
	cin >> Postorder;

	for (int i = 0; i < Postorder.size(); ++i)
	{
		
	}


	return 0;
}