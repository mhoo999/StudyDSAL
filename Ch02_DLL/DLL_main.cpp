#include "DLL.h"

using namespace std;

int main()
{
	int i			 = 0;
	int Count		 = 0;
	Node* List		 = nullptr;
	Node* NewNode	 = nullptr;
	Node* Current	 = nullptr;

	// ��� 5�� �߰�
	for (int i = 0; i < 5; ++i)
	{
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	Count = DLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = DLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	cout << "Inserting 3000 After [2]...\n";
	
	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = DLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = DLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ��� ��带 �޸𸮿��� ����
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