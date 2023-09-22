#include "DLL.h"

using namespace std;

int main()
{
	int i			 = 0;
	int Count		 = 0;
	Node* List		 = nullptr;
	Node* NewNode	 = nullptr;
	Node* Current	 = nullptr;

	// 노드 5개 추가
	for (int i = 0; i < 5; ++i)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = DLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	cout << "Inserting 3000 After [2]...\n";
	
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	Count = DLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = DLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// 모든 노드를 메모리에서 제거
	cout << "Destroying List...\n";

	Count = DLL_GetNodeCount(List);

	for (int i = 0; i < Count; ++i)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != nullptr)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}