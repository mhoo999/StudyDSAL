#include "AS.h"

void AS_CreateStack(ArrayStack*& Stack, int Capacity)
{
	// ������ ���� ����ҿ� ����
	Stack = new ArrayStack;

	// �Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ����
	Stack->Nodes = new Node[Capacity];
	
	// Capacity �� Top �ʱ�ȭ
	Stack->Capacity = Capacity;
	Stack->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// ��带 ���� ����ҿ��� ����
	delete(Stack->Nodes);

	// ������ ���� ����ҿ��� ����
	delete(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
	//int Position = Stack->Top--;
	return Stack->Nodes[Stack->Top--].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top+1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}