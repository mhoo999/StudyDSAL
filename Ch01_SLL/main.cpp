#include <iostream>

#include "Ch01-1_LinkedList.h"

using namespace std;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
int SLL_GetNodeCount(Node* Head);

int main() {
	cout << "Hello World!" << endl;

	//Node* List = NULL;
	//Node* NewNode = NULL;
	//Node* MyNode = NULL;

	// 노드 추가 연산
	//NewNode = SLL_CreateNode(117); // 자유 저장소에 노드 생성
	//SLL_AppendNode(&List, NewNode); // 생성한 노드를 List에 추가
	//NewNode = SLL_CreateNode(119); // 자유 저장소에 노드 생성
	//SLL_AppendNode(&List, NewNode); // 생성한 노드를 List에 추가

	// 노드 탐색 연산
	//SLL_AppendNode(&List, SLL_CreateNode(117)); // 노드를 생성하여 List에 추가
	//SLL_AppendNode(&List, SLL_CreateNode(119)); // 노드를 생성하여 List에 추가
	//MyNode = SLL_GetNodeAt(List, 1); // 두 번째 노드의 주소를 MyNode에 저장
	//cout << (MyNode->Data) << endl; // 119를 출력

	// 노드 삭제 연산
	//SLL_AppendNode(&List, SLL_CreateNode(117));
	//SLL_AppendNode(&List, SLL_CreateNode(119));
	//SLL_AppendNode(&List, SLL_CreateNode(212));
	//MyNode = SLL_GetNodeAt(List, 1); // 두 번째 노드의 주소를 MyNode에 저장
	//cout << (MyNode->Data) << endl; // 119를 출력
	//SLL_RemoveNode(&List, MyNode); // 두 번째 노드 제거
	//SLL_DestroyNode(MyNode); // 링크드 리스트에서 제거한 노드를 메모리에서 완전히 소멸시킴

	// 예제
	int i			= 0;
	int Count		= 0;
	Node* List		= NULL;
	Node* Current	= NULL;
	Node* NewNode	= NULL;

	// 노드 5개 추가
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << (Current->Data) << endl;
	}

	// 리스트의 세 번쨰 노드 뒤에 새 노드 삽입
	cout << "Inserting 3000 After [2]..." << endl;

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << (Current->Data) << endl;
	}

	// 모든 노드를 메모리에서 제거
	cout << "Destroying List..." << endl;

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}

		return 0;
	}

	return 0;
}