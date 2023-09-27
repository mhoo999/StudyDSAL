#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

class Node
{
public:
	ElementType Data;
};

class CircularQueue
{
private:

public:
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;

	static void CQ_CreateQueue(CircularQueue*& Queue, int Capacity);
	static void CQ_DestroyQueue(CircularQueue* Queue);
	static void CQ_Enqueue(CircularQueue* Queue, ElementType Data);
	static ElementType CQ_Dequeue(CircularQueue* Queue);
	static int CQ_GetSize(CircularQueue* Queue);
	static bool CQ_IsEmpty(CircularQueue* Queue);
	static bool CQ_IsFull(CircularQueue* Queue);
};