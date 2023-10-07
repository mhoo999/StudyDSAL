#pragma once

#include <iostream>

using namespace std;
using PriorityType = int;

class PQNode
{
public:
	PriorityType Priority;
	void* Data;
};

class PriorityQueue
{
public:
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
};

PriorityQueue* PQ_Create(int InitialSize);
void PQ_Destroy(PriorityQueue* PQ);
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
int PQ_GetParent(int Index);
int PQ_GetLeftChild(int Index);
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);
int PQ_IsEmpty(PriorityQueue* PQ);