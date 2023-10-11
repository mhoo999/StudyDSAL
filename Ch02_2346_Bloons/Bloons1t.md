#include <iostream>

using namespace std;

typedef struct Node
{
	int Number;
	int Data;
	Node* PrevNode;
	Node* NextNode;

	Node(int NewNumber, int NewData) : Number(NewNumber), Data(NewData), PrevNode(nullptr), NextNode(nullptr) {}
} Node;

class CDLL
{
	Node* Head;
	int Count;
public:
	CDLL() : Head(nullptr), Count(0) {}
	~CDLL()
	{
		while (Count-- > 0)
		{
			Node* DeleteNode = Head;
			Head = Head->NextNode;
			delete DeleteNode;
		}
	}

	Node* CreateNode(int NewNumber, int NewData) {	return new Node(NewNumber, NewData); }

	void DestroyNode(Node* Node) { delete Node; }

	void AppendNode(Node* NewNode)
	{
		if (Head == nullptr)
		{
			Head = NewNode;
			Head->PrevNode = Head;
			Head->NextNode = Head;
		}
		else
		{
			NewNode->PrevNode = Head->PrevNode;
			NewNode->NextNode = Head;

			Head->PrevNode->NextNode = NewNode;
			Head->PrevNode = NewNode;
		}
	}

	void MoveHead(int Data)
	{
		if (Data > 0)
		{
			while ((Data--) > 0)
			{
				Head = Head->NextNode;
			}
		}
		else
		{
			while ((Data++) < 0)
			{
				Head = Head->PrevNode;
			}
		}
	}

	void PrintRemove()
	{
		if (Head == nullptr) return;
		Node* Remove = Head;

		cout << Head->Number << " ";

		MoveHead(Remove->Data);

		Remove->NextNode->PrevNode = Remove->PrevNode;
		Remove->PrevNode->NextNode = Remove->NextNode;

		Remove->NextNode = nullptr;
		Remove->PrevNode = nullptr;

		delete Remove;
	}
};

int main()
{
	// 1번부터 N번까지 풍선이 원형으로 존재(CDLL)
	CDLL* List = new CDLL;
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Data;
		cin >> Data;
		List->AppendNode(List->CreateNode((i + 1), Data));
	}

	// 1번 노드의 데이터만큼 헤드를 이동하고, 해당 노드 삭제 ... 모든 노드 삭제까지 반복
	while (N-- > 0)
	{
		List->PrintRemove();
	}

	delete List;

	return 0;
}