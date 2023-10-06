#include "Heap.h"

Heap* HEAP_Create(int InitialSize)
{
	Heap* NewHeap = new Heap;
	NewHeap->Capacity = InitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = new HeapNode[NewHeap->Capacity];

	cout << "Size: " << sizeof(HeapNode) << endl;

	return NewHeap;
}

void HEAP_Destroy(Heap* H)
{
	delete[] H->Nodes;
	delete H;
}

void HEAP_Insert(Heap* H, ElementType NewData)
{
	int CurrentPosition = H->UsedSize;
	int ParentPosition = HEAP_GetParent(CurrentPosition);

	if (H->UsedSize == H->Capacity)
	{
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

	H->Nodes[CurrentPosition].Data = NewData;

	// �ļ� ó��
	while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
	{
		HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = HEAP_GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
	int CopySize = sizeof(HeapNode);
	HeapNode* Temp = new HeapNode;

	memcpy(Temp,				&H->Nodes[Index1],	CopySize);
	memcpy(&H->Nodes[Index1],	&H->Nodes[Index2],	CopySize);
	memcpy(&H->Nodes[Index2],	Temp,				CopySize);

	delete Temp;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	HEAP_SwapNodes(H, 0, H->UsedSize);

	LeftPosition = HEAP_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1)
	{
		int SelectedChild = 0;

		if (LeftPosition >= H->UsedSize)
			break;

		if (RightPosition >= H->UsedSize)
			SelectedChild = LeftPosition;
		else
		{
			if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}

		if (H->Nodes[LeftPosition].Data < H->Nodes[ParentPosition].Data)
		{
			HEAP_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}
		else
			break;

		LeftPosition = HEAP_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2))
	{
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

// Index�� ��ġ�� ����� �θ� ��尡 ��ġ�� �ε���: (Index -1 ) / 2
int HEAP_GetParent(int Index)
{
	return (int) ((Index - 1) / 2);
}

// Index�� ��ġ�� ����� ���� �ڽĵ��� ��ġ�� �ε���: (2 * Index) + 1 / (2 * Index) + 2
int HEAP_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

void HEAP_PrintNodes(Heap* H)
{
	int i = 0;
	for (i = 0; i < H->UsedSize; ++i)
	{
		cout << H->Nodes[i].Data << " ";
	}
	cout << endl;
}
