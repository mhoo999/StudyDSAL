#include "PriorityQueue.h"

void PrintNode(PQNode* Node)
{
	cout << "�۾���: " << Node->Data << "(�켱����: " << Node->Priority << ")\n";
}

int main()
{
	PriorityQueue* PQ = PQ_Create(3);
	PQNode Popped;

	PQNode Nodes[7] =
	{
		{34, (void*)"�ڵ�"},
		{12, (void*)"������"},
		{87, (void*)"Ŀ��Ÿ��"},
		{45, (void*)"�����ۼ�"},
		{35, (void*)"�����"},
		{66, (void*)"�̴۱�"}
	};

	PQ_Enqueue(PQ, Nodes[0]);
	PQ_Enqueue(PQ, Nodes[1]);
	PQ_Enqueue(PQ, Nodes[2]);
	PQ_Enqueue(PQ, Nodes[3]);
	PQ_Enqueue(PQ, Nodes[4]);
	PQ_Enqueue(PQ, Nodes[5]);

	cout << "ť�� ���� �ִ� �۾��� ��: " << PQ->UsedSize << endl;

	while (!PQ_IsEmpty(PQ))
	{
		PQ_Dequeue(PQ, &Popped);
		PrintNode(&Popped);
	}

	return 0;
}