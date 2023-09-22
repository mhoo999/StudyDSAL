#include "CDLL.h"

// 노드 생성
Node* CDLL_CreateNode(ElementType NewData)
{
	Node* NewNode = new Node;

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 소멸
void CDLL_DestroyNode(Node* Node)
{
	delete(Node);
}

// 노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드가 NULL이면 새로운 노드가 Head가 된다
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->PrevNode = *Head;
		(*Head)->NextNode = *Head;
	}
	else
	{
		// 테일과 헤드 사이에 NewNode를 삽입한다
		Node* Tail = (*Head)->PrevNode;

		NewNode->PrevNode = Tail;
		NewNode->NextNode = *Head;

		
		(*Head)->PrevNode = NewNode;
		//Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		//NewNode->NextNode = *Head;
		//NewNode->PrevNode = Tail; // 새로운 테일의 PrevNode가 기존의 테일을 가리킨다
	}
}

// 노드 삽입
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


// 노드 제거
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

// 노드 탐색
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 개수 세기
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