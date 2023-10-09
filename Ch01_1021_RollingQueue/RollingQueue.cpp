#include <iostream>

using namespace std;
using ElementType = int;

class CDLLNode
{
public:
	ElementType Data;
	CDLLNode* PrevNode;
	CDLLNode* NextNode;
	static CDLLNode* CreateNode(ElementType Data)
	{
		CDLLNode* NewNode = new CDLLNode;
		NewNode->Data = Data;
		NewNode->PrevNode = nullptr;
		NewNode->NextNode = nullptr;

		return NewNode;
	}

	static void DestroyNode(CDLLNode* Node)
	{
		delete Node;
	}

	static void AppendNode(CDLLNode*& Head, CDLLNode* NewNode)
	{
		if (Head == nullptr)
		{
			Head = NewNode;

			Head->NextNode = Head;
			Head->PrevNode = Head;
		}
		else
		{
			NewNode->PrevNode = Head->PrevNode;
			NewNode->NextNode = Head;

			Head->PrevNode->NextNode = NewNode;
			Head->PrevNode = NewNode;
		}
	}

	static int GetNextCount(CDLLNode* Head, int Target)
	{
		int Count = 0;
		CDLLNode* Current = Head;

		while (Current->Data != Target)
		{
			Current = Current->NextNode;
			Count++;
		}

		return Count;
	}

	static int GetPrevCount(CDLLNode* Head, int Target)
	{
		int Count = 0;
		CDLLNode* Current = Head;

		while (Current->Data != Target)
		{
			Current = Current->PrevNode;
			Count++;
		}

		return Count;
	}

	static void RemoveHead(CDLLNode*& Head)
	{
		CDLLNode* Remove = Head;

		Head->PrevNode->NextNode = Head->NextNode;
		Head->NextNode->PrevNode = Head->PrevNode;

		Head = Head->NextNode;

		Remove->NextNode = nullptr;
		Remove->PrevNode = nullptr;

		DestroyNode(Remove);
	}

	static void MoveLeft(CDLLNode*& Head)
	{
		Head = Head->PrevNode;
	}

	static void MoveRight(CDLLNode*& Head)
	{
		Head = Head->NextNode;
	}
};

int main()
{
	// 2��, 3�� ���� �� ���� ������ Front�� �� �� �ִ� ������ ����
	// 1�� ������ �����Ͽ� ���Ҹ� ����

	// ť�� ũ�� M�� �̾Ƴ����� �ϴ� ���� ���� M
	int M = 0;
	int N = 0;
	cin >> M >> N;

	// M ��ŭ �̾Ƴ� ���� ��ġ�� ������� �Է�
	int Input[50];
	for (int i = 0; i < N; ++i)
		cin >> Input[i];

	CDLLNode* Head = nullptr;
	CDLLNode* NewNode = nullptr;

	// ��ȯ ť�� DLL�� ����
	for (int i = 0; i < M; ++i)
	{
		NewNode = CDLLNode::CreateNode(i + 1);
		CDLLNode::AppendNode(Head, NewNode);
	}

	int MinValue = 0;

	for (int i = 0; i < N; ++i)
	{
		if (Head->Data == Input[i])
		{
			CDLLNode::RemoveHead(Head);
		}
		else
		{
			if (CDLLNode::GetNextCount(Head, Input[i]) < CDLLNode::GetPrevCount(Head, Input[i]))
			{
				int Move = CDLLNode::GetNextCount(Head, Input[i]);
				for (int j = 0; j < Move; ++j)
				{
					CDLLNode::MoveRight(Head);
					MinValue++;
				}
				CDLLNode::RemoveHead(Head);
			}
			else
			{
				int Move = CDLLNode::GetPrevCount(Head, Input[i]);
				for (int j = 0; j < Move; ++j)
				{
					CDLLNode::MoveLeft(Head);
					MinValue++;
				}
				CDLLNode::RemoveHead(Head);
			}
		}
	}

	cout << MinValue;

	return 0;
}