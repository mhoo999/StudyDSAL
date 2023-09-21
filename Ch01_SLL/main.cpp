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

	// ��� �߰� ����
	//NewNode = SLL_CreateNode(117); // ���� ����ҿ� ��� ����
	//SLL_AppendNode(&List, NewNode); // ������ ��带 List�� �߰�
	//NewNode = SLL_CreateNode(119); // ���� ����ҿ� ��� ����
	//SLL_AppendNode(&List, NewNode); // ������ ��带 List�� �߰�

	// ��� Ž�� ����
	//SLL_AppendNode(&List, SLL_CreateNode(117)); // ��带 �����Ͽ� List�� �߰�
	//SLL_AppendNode(&List, SLL_CreateNode(119)); // ��带 �����Ͽ� List�� �߰�
	//MyNode = SLL_GetNodeAt(List, 1); // �� ��° ����� �ּҸ� MyNode�� ����
	//cout << (MyNode->Data) << endl; // 119�� ���

	// ��� ���� ����
	//SLL_AppendNode(&List, SLL_CreateNode(117));
	//SLL_AppendNode(&List, SLL_CreateNode(119));
	//SLL_AppendNode(&List, SLL_CreateNode(212));
	//MyNode = SLL_GetNodeAt(List, 1); // �� ��° ����� �ּҸ� MyNode�� ����
	//cout << (MyNode->Data) << endl; // 119�� ���
	//SLL_RemoveNode(&List, MyNode); // �� ��° ��� ����
	//SLL_DestroyNode(MyNode); // ��ũ�� ����Ʈ���� ������ ��带 �޸𸮿��� ������ �Ҹ��Ŵ

	// ����
	int i			= 0;
	int Count		= 0;
	Node* List		= NULL;
	Node* Current	= NULL;
	Node* NewNode	= NULL;

	// ��� 5�� �߰�
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << (Current->Data) << endl;
	}

	// ����Ʈ�� �� ���� ��� �ڿ� �� ��� ����
	cout << "Inserting 3000 After [2]..." << endl;

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] : " << (Current->Data) << endl;
	}

	// ��� ��带 �޸𸮿��� ����
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