#include "DLL.h"
using namespace std;

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData;
	NewNode->PrevNode = nullptr;
	NewNode->NextNode = nullptr;

	return NewNode;
}


// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
	delete Node;
}


// 노드 추가
void DLL_AppendNode(Node*& Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다
	if (Head == nullptr)
	{
		Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다
		Node* Tail = Head;
		while (Tail->NextNode != nullptr)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; // 기존 테일을 새로운 테일의 PrevNode가 가리킨다 
	}
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != nullptr)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}

// 노드 제거
void DLL_RemoveNode(Node*& Head, Node* Remove)
{
	if (Head == Remove)
	{
		Head = Remove->NextNode;
		if (Head != nullptr)
			Head->PrevNode = nullptr;

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != nullptr)
			Remove->PrevNode->NextNode = Temp->NextNode;
		if (Remove->NextNode != nullptr)
			Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 개수 세기
int DLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == nullptr)
		cout << "Prev : nullptr";
	else
		cout << "Prev: " << _Node->PrevNode->Data;
	cout << "Current : " << _Node->Data;
	if (_Node->NextNode == nullptr)
		cout << "Next : nullptr";
	else
		cout << "Next : " << _Node->NextNode->Data;
}