#include "PriorityQueue.h"

PriorityQueue* PQ_Create(int InitialSize)
{
	PriorityQueue* NewPQ = new PriorityQueue;
	NewPQ->Capacity = InitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = new PQNode[NewPQ->Capacity];

	return NewPQ;
}

void PQ_Destroy(PriorityQueue* PQ)
{
	delete[] PQ->Nodes;
	delete PQ;
}

int PQ_GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
	int CopySize = sizeof(PQNode);
	PQNode* Temp = new PQNode[CopySize];

	memcpy(Temp, &PQ->Nodes[Index1], CopySize);
	memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize);
	memcpy(&PQ->Nodes[Index2], Temp, CopySize);

	delete Temp;
}

int PQ_IsEmpty(PriorityQueue* PQ)
{
	return (PQ->UsedSize == 0);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData)
{
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent(CurrentPosition);

	if (PQ->UsedSize == PQ->Capacity)
	{
		if (PQ->Capacity == 0)
			PQ->Capacity = 1;

		// UsedSize�� Capacity�� �����ϸ� Capcity�� 2��� �ø���.
		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}

	PQ->Nodes[CurrentPosition] = NewData;

	// �ļ� ó��, ����� Heapify
	while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
	{
		PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent(CurrentPosition);
	}

	PQ->UsedSize++;
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	// Root�� �ּڰ��� ����
	// memcpy = �޸� ������ �����ϴ� �Լ�, ù��° ��忡 �ִ� �����͸� Root�� ����Ű�� ��ġ�� ����
	memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
	// memset = �޸𸮸� Ư�� ������ �����ϴ� �Լ�, ù��° ��忡 �ִ� �����͸� 0���� �ʱ�ȭ
	memset(&PQ->Nodes[0], 0, sizeof(PQNode));

	// ���� ù ��° ��ҿ� ������ ����� ���� ����
	PQ->UsedSize--;
	PQ_SwapNodes(PQ, 0, PQ->UsedSize);

	LeftPosition = PQ_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	// �� ���� �Ӽ��� ������ ������ �ڽ� ������ ��ȯ�� �ݺ�, ����� Heapify
	while (1)
	{
		int SelectChild = 0;

		if (LeftPosition >= PQ->UsedSize)
			break;

		if (RightPosition >= PQ->UsedSize)
			SelectChild = LeftPosition;
		else
		{
			if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
				SelectChild = RightPosition;
			else
				SelectChild = LeftPosition;
		}

		if (PQ->Nodes[SelectChild].Priority < PQ->Nodes[ParentPosition].Priority)
		{
			PQ_SwapNodes(PQ, ParentPosition, SelectChild);
			ParentPosition = SelectChild;
		}
		else
			break;

		LeftPosition = PQ_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (PQ->UsedSize < (PQ->Capacity / 2))
	{
		PQ->Capacity / 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}
}