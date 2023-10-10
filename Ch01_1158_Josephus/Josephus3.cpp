#include <iostream>

using namespace std;

typedef struct Node
{
	int Data;
	Node* PrevNode;
	Node* NextNode;

	Node(int NewData) : Data(NewData), PrevNode(nullptr), NextNode(nullptr) {}
};

class CLL
{
	Node* Head;
	Node* Tail;
	int Count;

public:
	CLL() : Head(nullptr), Tail(nullptr), Count(0) {}
	~CLL()
	{
		Node* DeleteTarget = Head;
		Head = Head->NextNode;
		delete DeleteTarget;
	}

	Node* CLLCreateNode(int NewData)
	{
		if (NewData == NULL)
			return;

		return new Node(NewData);
	}

	void CLLDestroyNode(Node* Node)
	{
		delete Node;
	}

	void CLLAppendNode(Node* NewNode)
	{
		if (NewNode == nullptr)
			return;

		if (Head == nullptr)
		{
			Head = NewNode;
			Head->PrevNode = NewNode;
			Head->NextNode = NewNode;

			Tail = NewNode;
			Tail->PrevNode = NewNode;
			Tail->NextNode = NewNode;
		}
		else
		{
			NewNode->PrevNode = Tail;
			NewNode->NextNode = Head;

			Head->PrevNode = NewNode;
			Tail->NextNode = NewNode;
		}

		Count++;
	}

	void CLLCreateList(int Size)
	{
		Node* NewNode = nullptr;

		for (int i = 0; i < Size; ++i)
		{
			NewNode = CLLCreateNode(i + 1);
			CLLAppendNode(NewNode);
		}
	}

	void CLLPrintRemove(Node* Remove)
	{
		if (Remove == nullptr)
			return;

		cout << Remove->Data;

		if (Head == Remove)
		{
			Head = Head->NextNode;
			Head->PrevNode = Remove->PrevNode;
			Tail->NextNode = Head;
		}
		else
		{
			Node* Current = Head;
			while (Current->NextNode != Remove)
			{
				Current = Current->NextNode;
			}
			Current->NextNode = Remove->NextNode;
			Current->NextNode->PrevNode = Remove->PrevNode;
		}

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;

		Count--;
	}

	Node* CLLGetNextTarget(int TargetNumber)
	{
		Node* NextTarget = nullptr;

		return NextTarget;
	}

	int CLLCount()
	{
		return Count;
	}

	bool CLLIsEmpty()
	{
		return Count == 0;
	}
};

int main()
{
	CLL* List = new CLL;

	int N, K;
	cin >> N >> K;

	List->CLLCreateList(N);

	while (!List->CLLIsEmpty())
	{

	}

	return 0;
}