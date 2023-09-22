#include <iostream>
#include "SDLL.h"

using namespace std;

Node* CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Node)
{
	delete(Node);
}

void AppendNode(Node*& Head, Node* NewNode)
{
	if (Head == NULL)
	{
		Head->PrevNode = NewNode;
		NewNode->NextNode = Head;
		Head = NewNode;
	}
	else
	{
		Node* Tail = Head;
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

Node* GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void RemoveNode(Node*& Head, Node* Remove)
{
	if (Head == Remove)
	{
		Head = Remove->NextNode;
		if (Remove->NextNode != NULL)
			Head->PrevNode = NULL;
		
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
	else
	{
		Node* Current = Remove;
		
		Current->PrevNode->NextNode = Remove->NextNode;
		Remove->PrevNode = NULL;

		if (Remove->NextNode != NULL)
		{
			Current->NextNode->PrevNode = Remove->PrevNode;
			Remove->NextNode = NULL;
		}
	}
}

void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}

void InsertBefore(Node** pHead, Node* Current, Node* NewNode)
{
	if ((*pHead) == Current)
	{
		*pHead = NewNode;
		NewNode->NextNode = Current;
		Current->PrevNode = NewNode;
	}
	else
	{
		Current->PrevNode->NextNode = NewNode;
		NewNode->PrevNode = Current->PrevNode;

		Current->PrevNode = NewNode;
		NewNode->NextNode = Current;
	}
}

int NodeCount(Node* Head)
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