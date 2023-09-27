#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main()
{
	int i;
	CircularQueue* Queue;

	CircularQueue::CQ_CreateQueue(Queue, 10);

	CircularQueue::CQ_Enqueue(Queue, 1);
	CircularQueue::CQ_Enqueue(Queue, 2);
	CircularQueue::CQ_Enqueue(Queue, 3);
	CircularQueue::CQ_Enqueue(Queue, 4);

	for (int i = 0; i < 3; ++i)
	{
		cout << "\nDequeue: " << CircularQueue::CQ_Dequeue(Queue) << ", Front: " << Queue->Front << ", Rear: " << Queue->Rear;
	}

	i = 100;
	while (CircularQueue::CQ_IsFull(Queue) == 0)
	{
		CircularQueue::CQ_Enqueue(Queue, i++);
	}

	cout << "\nCapacity: " << Queue->Capacity << ", Size: " << CircularQueue::CQ_GetSize(Queue);

	while (CircularQueue::CQ_IsEmpty(Queue) == 0)
	{
		cout << "\nDequeue: " << CircularQueue::CQ_Dequeue(Queue) << ", Front: " << Queue->Front << ", Rear: " << Queue->Rear;
	}

	CircularQueue::CQ_DestroyQueue(Queue);

	return 0;
}