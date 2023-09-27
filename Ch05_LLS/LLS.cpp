#include "LLS.h"
#include <string>

void LLS_CreateStack(LinkedListStack*& Stack)
{
	// 스택을 자유 저장소에 생성
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

	// 스택을 자유 저장소에서 해제
	delete[] Stack;
}

Node* LLS_CreateNode(const char* NewData)
{
	Node* NewNode = new Node;
	NewNode->Data = new char[strlen(NewData) + 1];

	strcpy(NewNode->Data, NewData); // 데이터를 저장한다

	NewNode->NextNode = nullptr; // 다음 노드에 대한 포인터는 nullptr로 초기화한다

	return NewNode; // 노드의 주소를 반환한다
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
		// 스택의 Top에 신규 노드를 연결한다
		Stack->Top->NextNode = NewNode;
	}

	// 스택의 Top 필드에 새 노드의 주소를 등록한다
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	// LSS_Pop() 함수가 반환할 최상위 노드 저장
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}
	else
	{
		// Top 아래에 있던 노드를 새로운 CurrentTop에 저장
		Node* CurrentTop = Stack->List;
		while (CurrentTop != nullptr && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		// CurrentTop을 Top에 저장
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
