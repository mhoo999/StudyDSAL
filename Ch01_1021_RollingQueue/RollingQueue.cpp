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
	// 2번, 3번 연산 중 가장 빠르게 Front로 갈 수 있는 연산을 선택
	// 1번 연산을 실행하여 원소를 삭제

	// 큐의 크기 M과 뽑아내려고 하는 수의 개수 M
	int M = 0;
	int N = 0;
	cin >> M >> N;

	// M 만큼 뽑아낼 수의 위치를 순서대로 입력
	int Input[50];
	for (int i = 0; i < N; ++i)
		cin >> Input[i];

	CDLLNode* Head = nullptr;
	CDLLNode* NewNode = nullptr;

	// 순환 큐를 DLL로 셋팅
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