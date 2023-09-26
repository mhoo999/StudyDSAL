#include "Ch06_LLS.h"

void LLS_CreateStack(LinkedListStack*& Stack)
{
	Stack = new LinkedListStack;

	Stack->List = nullptr;
	Stack->Top = nullptr;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		LLS_DestroyNode(LLS_Pop(Stack));
	}
	delete(Stack);
}

Node* LLS_CreateNode(const char* Data)
{
	Node* NewNode = new Node;
	NewNode->Data = new char[strlen(Data) + 1];

	strcpy(NewNode->Data, Data);

	NewNode->NextNode = nullptr;
	return NewNode;
}

void LLS_DestroyNode(Node* _Node)
{
	delete(_Node->Data);
	delete(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == nullptr)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}
	else
	{
		Node* CurrentTop = Stack->List;
		while (CurrentTop != nullptr && CurrentTop->NextNode != TopNode)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = nullptr;
	}
	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == nullptr);
}