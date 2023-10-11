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
			Tail = NewNode;

			Head->PrevNode = Tail;
			Head->NextNode = Tail;

			Tail->PrevNode = Head;
			Tail->NextNode = Head;
		}
		else
		{
			NewNode->PrevNode = Tail;
			NewNode->NextNode = Head;

			Head->PrevNode = NewNode;
			Tail->NextNode = NewNode;

			Tail = NewNode;
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

	void CLLRemoveNode(Node* Remove)
	{
		if (Remove == nullptr)
			return;

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

			if (Tail == Remove)
				Tail = Remove->PrevNode;
		}

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;

		Count--;
	}

	Node* CLLGetNextTarget(Node*& Target, int TargetNumber)
	{
		Node* NextTarget = nullptr;

		if (Target == nullptr)
		{
			Target = Head;
		}
		
		NextTarget = Target;
		while ((--TargetNumber) > 0)
		{
			NextTarget = NextTarget->NextNode;
		}

		return NextTarget;
	}

	void CLLPrintNode(Node* Target)
	{
		cout << Target->Data;

		if (Count > 1)
			cout << ", ";
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
	Node* Target = nullptr;
	Node* NextTarget = nullptr;

	int N, K;
	cin >> N >> K;

	List->CLLCreateList(N);

	NextTarget = List->CLLGetNextTarget(Target, K);

	cout << "<";
	while (!List->CLLIsEmpty())
	{
		// 회차별 Target 리타겟팅
		Target = NextTarget;

		// Target 출력
		List->CLLPrintNode(Target);
		
		// NextTarget 저장
		NextTarget = List->CLLGetNextTarget(Target, K);

		// Target 삭제
		List->CLLRemoveNode(Target);
	}
	cout << ">";

	return 0;
}