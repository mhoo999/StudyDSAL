#include "LL.h"

using namespace std;

int main()
{
	int i			= 0;
	int Count		= 0;
	Node* List		= nullptr;
	Node* Current	= nullptr;
	Node* NewNode	= nullptr;

	// 노드 5개 추가
	for (int i = 0; i < 5; ++i)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(List, NewNode);
	}

	// 헤드 앞에 (-1)노드 추가
	NewNode = SLL_CreateNode(-1);
	SLL_InsertHead(List, NewNode);

	// 헤드 앞에 (-2)노드 추가
	NewNode = SLL_CreateNode(-2);
	SLL_InsertHead(List, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 리스트의 세 번째 노드 뒤에 새 노드 삽입
	cout << "Inserting 3000 After [2]...\n";

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 모든 노드를 메모리에서 제거
	cout << "Destroying List...\n";

	for (int i = 0; i < Count; ++i)
	{
		Current = SLL_GetNodeAt(List, i);

		if (Current != NULL)
		{
			SLL_RemoveNode(List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}