#include "LL.h"

using namespace std;

int main()
{
	int i			= 0;
	int Count		= 0;
	Node* List		= nullptr;
	Node* Current	= nullptr;
	Node* NewNode	= nullptr;

	// ��� 5�� �߰�
	for (int i = 0; i < 5; ++i)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(List, NewNode);
	}

	// ��� �տ� (-1)��� �߰�
	NewNode = SLL_CreateNode(-1);
	SLL_InsertHead(List, NewNode);

	// ��� �տ� (-2)��� �߰�
	NewNode = SLL_CreateNode(-2);
	SLL_InsertHead(List, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ����Ʈ�� �� ��° ��� �ڿ� �� ��� ����
	cout << "Inserting 3000 After [2]...\n";

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ��� ��带 �޸𸮿��� ����
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