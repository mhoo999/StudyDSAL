#include "LLS.h"

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
		Node* Popped = LLS_Pop(Stack));
		LLS_DestroyNode(Popped);
	}

	// ������ ���� ����ҿ��� ����
	delete(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = new Node;
	NewNode->Data = new NewData + 1;

	strcpy()
}