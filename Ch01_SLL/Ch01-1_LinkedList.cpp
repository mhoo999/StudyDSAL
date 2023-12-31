#include <iostream>

#include "Ch01-1_LinkedList.h"

using namespace std;

// 노드 생성(오류)
//Node* SLL_CreateNode(ElementType NewData)
//{
//	Node NewNode;
//
//	NewNode.Data = NewData; // 자동 메모리에 새로운 노드 생성
//	NewNode.NextData = NULL;
//
//	return &NewNode; // NewNode가 생성된 메모리의 주소를 반환
//} // 함수가 종료되면서 NewNode는 자동 메모리에서 제거된다.

// 노드 생성
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData; // 데이터를 저장한다.
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 최기화한다.

	return NewNode; // 노드의 주소를 반환한다.
}

// 노드 소멸
void SLL_DestroyNode(Node* Node)
{
	delete(Node);
}

// 노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 삭제
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

// 노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// 새로운 헤드 삽입
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

// 노드 개수 세기 연산
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

// 특정 노드 앞에 새로운 노드를 삽입하는 연산
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

// 모든 노드를 한 번에 제거하는 함수
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

// 완료