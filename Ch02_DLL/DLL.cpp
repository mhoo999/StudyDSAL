#include "DLL.h"
using namespace std;

// ��� ����
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData;
	NewNode->PrevNode = nullptr;
	NewNode->NextNode = nullptr;

	return NewNode;
}


// ��� �Ҹ�
void DLL_DestroyNode(Node* Node)
{
	delete Node;
}


// ��� �߰�
void DLL_AppendNode(Node*& Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�
	if (Head == nullptr)
	{
		Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�
		Node* Tail = Head;
		while (Tail->NextNode != nullptr)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; // ���� ������ ���ο� ������ PrevNode�� ����Ų�� 
	}
}

// ��� ����
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

// ��� ����
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

// ��� Ž��
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ���� ����
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