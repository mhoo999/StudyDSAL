#include "LLS.h"
#include <string>

void LLS_CreateStack(LinkedListStack*& Stack)
{
	// ������ ���� ����ҿ� ����
	Stack = new LinkedListStack;

	Stack->List = nullptr;
	Stack->Top = nullptr;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	// ������ ���� ����ҿ��� ����
	delete[] Stack;
}

Node* LLS_CreateNode(const char* NewData)
{
	Node* NewNode = new Node;
	NewNode->Data = new char[strlen(NewData) + 1];

	strcpy(NewNode->Data, NewData); // �����͸� �����Ѵ�

	NewNode->NextNode = nullptr; // ���� ��忡 ���� �����ʹ� nullptr�� �ʱ�ȭ�Ѵ�

	return NewNode; // ����� �ּҸ� ��ȯ�Ѵ�
}

void LLS_DestroyNode(Node* _Node)
{
	delete[] _Node->Data;
	delete[] _Node;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == nullptr)
	{
		Stack->List = NewNode;
	}
	else
	{
		// ������ Top�� �ű� ��带 �����Ѵ�
		Stack->Top->NextNode = NewNode;
	}

	// ������ Top �ʵ忡 �� ����� �ּҸ� ����Ѵ�
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	// LSS_Pop() �Լ��� ��ȯ�� �ֻ��� ��� ����
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}
	else
	{
		// Top �Ʒ��� �ִ� ��带 ���ο� CurrentTop�� ����
		Node* CurrentTop = Stack->List;
		while (CurrentTop != nullptr && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		// CurrentTop�� Top�� ����
		Stack->Top = CurrentTop;
		CurrentTop->NextNode = nullptr;
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

bool LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == nullptr);
}
