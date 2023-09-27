#include "CircularQueue.h"

void CircularQueue::CQ_CreateQueue(CircularQueue*& Queue, int Capacity)
{
	Queue = new CircularQueue; // 钮甫 赛俊 积己

	Queue->Nodes = new Node[Capacity + 1]; // Capacity+1 父怒 赛俊 积己

	Queue->Capacity = Capacity;
	Queue->Front = 0;
	Queue->Rear = 0;
}

void CircularQueue::CQ_DestroyQueue(CircularQueue* Queue)
{
	delete[] Queue->Nodes;
	delete[] Queue;
}

void CircularQueue::CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
	int Position = 0;

	if (Queue->Rear == Queue->Capacity)
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		Position = Queue->Rear++;

	Queue->Nodes[Position].Data = Data;
}

ElementType CircularQueue::CQ_Dequeue(CircularQueue* Queue)
{
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[Position].Data;
}

int CircularQueue::CQ_GetSize(CircularQueue* Queue)
{
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

bool CircularQueue::CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

bool CircularQueue::CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else
		return (Queue->Rear + 1) == Queue->Front;
}