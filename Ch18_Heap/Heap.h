#pragma once

#include <iostream>

using namespace std;
using ElementType = int;

class HeapNode
{
public:
	ElementType Data;
};

class Heap
{
public:
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
};

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_PrintNodes(Heap* H);