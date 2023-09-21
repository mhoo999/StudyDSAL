#include <iostream>

#include "Ch01-1_LinkedList.h"

using namespace std;

// ��� ����(����)
//Node* SLL_CreateNode(ElementType NewData)
//{
//	Node NewNode;
//
//	NewNode.Data = NewData; // �ڵ� �޸𸮿� ���ο� ��� ����
//	NewNode.NextData = NULL;
//
//	return &NewNode; // NewNode�� ������ �޸��� �ּҸ� ��ȯ
//} // �Լ��� ����Ǹ鼭 NewNode�� �ڵ� �޸𸮿��� ���ŵȴ�.

// ��� ����
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData; // �����͸� �����Ѵ�.
	NewNode->NextNode = NULL; // ���� ��忡 ���� �����ʹ� NULL�� �ֱ�ȭ�Ѵ�.

	return NewNode; // ����� �ּҸ� ��ȯ�Ѵ�.
}

// ��� �Ҹ�
void SLL_DestroyNode(Node* Node)
{
	delete(Node);
}

// ��� �߰�
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

// ��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ����
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

// ��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// ���ο� ��� ����
void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// ��� ���� ���� ����
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// Ư�� ��� �տ� ���ο� ��带 �����ϴ� ����
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
	if ((*Head) == NewHead)
	{
		NewHead->NextNode = (*Head);
	}
	else
	{
		Node* Current = (*Head);
		while (Current != NULL && NewHead->NextNode != Current)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			NewHead->NextNode = Current->NextNode;
			Current->NextNode = NewHead;
		}
	}
}

// ��� ��带 �� ���� �����ϴ� �Լ�
void SLL_DestroyAll(Node** Head)
{
	Node* Current = *Head;
	Node* Temp;

	while (Current != NULL)
	{
		Temp = Current->NextNode;
		Current->NextNode = NULL;
		Current = Temp;
	}
}

// �Ϸ�