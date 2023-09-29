#include "CDLL.h"

using namespace std;

int main()
{
	int i			= 0;
	int Count		= 0;
	Node* List		= nullptr;
	Node* NewNode	= nullptr;
	Node* Current	= nullptr;

	// 노드 5개 추가
	for (int i = 0; i < 5; ++i)
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(List, NewNode);
	}

	// 리스트 출력
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = CDLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	cout << "Inserting 3000 After [2]...\n";
	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

	cout << "Removing Node at 2...\n";
	Current = CDLL_GetNodeAt(List, 2);
	CDLL_RemoveNode(List, Current);
	CDLL_DestroyNode(Current);

	// 리스트 출력
	// (노드 개수의 2배만큼 루프를 돌며 환형임을 확인한다)
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count * 2; ++i)
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 모든 노드를 메모리에서 제거
	cout << "Destroying List...\n";
	Count = CDLL_GetNodeCount(List);

	for (int i = 0; i < Count; ++i)
	{
		Current = CDLL_GetNodeAt(List, i);

		if (Current != NULL)
		{
			CDLL_RemoveNode(List, Current);
			CDLL_DestroyNode(Current);
		}
	}

	return 0;
}