#include <iostream>
#include "SDLL.h"

using namespace std;

void AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;

		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;

		(*Head)->PrevNode = NewNode;
		NewNode->NextNode = *Head;
	}
}

void RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
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