#include "CDLL.h"

using namespace std;

int main()
{
	int i			= 0;
	int Count		= 0;
	Node* List		= nullptr;
	Node* NewNode	= nullptr;
	Node* Current	= nullptr;

	// ��� 5�� �߰�
	for (int i = 0; i < 5; ++i)
	{
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(List, NewNode);
	}

	// ����Ʈ ���
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count; ++i)
	{
		Current = CDLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	cout << "Inserting 3000 After [2]...\n";
	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	CDLL_InsertAfter(Current, NewNode);

	cout << "Removing Node at 2...\n";
	Current = CDLL_GetNodeAt(List, 2);
	CDLL_RemoveNode(List, Current);
	CDLL_DestroyNode(Current);

	// ����Ʈ ���
	// (��� ������ 2�踸ŭ ������ ���� ȯ������ Ȯ���Ѵ�)
	Count = CDLL_GetNodeCount(List);
	for (int i = 0; i < Count * 2; ++i)
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		cout << "List[" << i << "] : " << Current->Data << "\n";
	}

	// ��� ��带 �޸𸮿��� ����
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