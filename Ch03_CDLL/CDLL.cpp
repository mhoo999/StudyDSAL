#include "CDLL.h"

// ��� ����
Node* CDLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void CDLL_DestroyNode(Node* Node)
{
	delete(Node);
}

// ��� �߰�
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��尡 NULL�̸� ���ο� ��尡 Head�� �ȴ�
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->PrevNode = *Head;
		(*Head)->NextNode = *Head;
	}
	else
	{
		// ���ϰ� ��� ���̿� NewNode�� �����Ѵ�
		Node* Tail = (*Head)->PrevNode;

		NewNode->PrevNode = Tail;
		NewNode->NextNode = *Head;

		
		(*Head)->PrevNode = NewNode;
		//Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		//NewNode->NextNode = *Head;
		//NewNode->PrevNode = Tail; // ���ο� ������ PrevNode�� ������ ������ ����Ų��
	}
}

// ��� ����
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}


// ��� ����
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
	else
	{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
}

// ��� Ž��
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ���� ����
int CDLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;

		if (Current == Head)
			break;
	}

	return Count;
}