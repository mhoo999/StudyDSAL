#include <iostream>

using namespace std;
using ElementType = int;

typedef struct Node
{
	ElementType Data;
	Node* NextNode;

	Node(ElementType NewData) : Data(NewData), NextNode(nullptr) {}
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
		Node* DeketeTarget = Head;
		Head = Head->NextNode;
		delete DeketeTarget;
	}

	Node* CreateNode(ElementType NewData)
	{
		return new Node(NewData);
	}

	void DestroyNode(Node* Node)
	{
		delete Node;
	}

	void AppendNode(Node*& Head, Node* NewNode)
	{
		if (Head == nullptr)
		{
			Head = NewNode;
			Head->NextNode = NewNode;

			Tail = NewNode;
			Tail->NextNode = NewNode;
		}
		else
		{
			NewNode->NextNode = Head;
			Tail->NextNode = NewNode;
			Tail = NewNode;
		}

		Count++;
	}

	void RemoveNode()
	{
		Node* DestroyTarget = Head;
		Tail->NextNode = Head->NextNode;
		Head = Head->NextNode;

		DestroyNode(DestroyTarget);
		/*
		if (Head == Remove)
		{
			Head = Head->NextNode;
			Head->NextNode = Head;
		}
		else
		{
			Node* Current = Head;
			while (Current->NextNode != Remove)
				Current = Current->NextNode;

			Current->NextNode = Remove->NextNode;
			Remove->NextNode = nullptr;

			if (Tail == Remove)
				Tail = Current;
		}

		Count--;
		DestroyNode(Remove);*/
	}

	bool IsEmpty(Node* Head)
	{
		return (Count == 0);
	}

	void GetNodeAt(int Location)
	{
		while (Head != nullptr && (--Location) >= 0)
		{
			Head = Head->NextNode;
		}

		/*if (Head == nullptr)
			return nullptr;

		Node* Current = Head;
		while (Current != nullptr && (--Location) >= 0)
		{
			Current = Current->NextNode;
		}*/

		return;
	}

	void CreateList(int N)
	{
		Node* NewNode = nullptr;

		for (int i = 0; i < N; ++i)
		{
			NewNode = CreateNode(i + 1);
			AppendNode(Head, NewNode);
		}
	}

	void Print()
	{
		Node* Current = Head->NextNode;

		cout << Head->Data << ' ';
		while (Current != nullptr && Current != Head)
		{
			cout << Current->Data << ' ';
			Current = Current->NextNode;
		}
		cout << '\n';
	}

	void PrintList(int K)
	{
		while (Head != nullptr)
		{
			Print();
			GetNodeAt(K-1);
			cout << Head->Data;
			RemoveNode();
			if (Count > 1) cout << ", ";
		}

		////Node* TargetPrev = GetNodeAt(K - 2);
		//while (!IsEmpty(Head))
		//{
		//	///Node* Target = TargetPrev->NextNode;

		//	cout << Target->Data;

		//	RemoveNode(Target);

		//	if (Count > 0)
		//	{
		//		TargetPrev = GetNodeAt(K - 1);
		//		cout << ", ";
		//	}
		//}
	}
};

int main()
{
	CLL* List = new CLL;
	//Node* NewNode = nullptr;

	// 원을 이루는 사람의 수 'N'과 제거할 숫자 'K'를 입력 받음
	int N, K;
	cin >> N >> K;

	// N만큼의 CLL을 구현
	List->CreateList(N);

	// CLL이 Empty가 될 때까지 K번째 노드의 데이터를 출력하고, 노드를 제거
	cout << "<";

	List->PrintList(K);

	cout << ">";
}