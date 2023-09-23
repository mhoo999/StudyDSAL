#include "AS.h"

void AS_CreateStack(ArrayStack*& Stack, int Capacity)
{
	// 스택을 자유 저장소에 생성
	Stack = new ArrayStack;

	// 입력된 Capacity만큼의 노드를 자유 저장소에 생성
	Stack->Nodes = new Node[Capacity];
	
	// Capacity 및 Top 초기화
	Stack->Capacity = Capacity;
	Stack->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// 노드를 자유 저장소에서 해제
	delete(Stack->Nodes);

	// 스택을 자유 저장소에서 해제
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