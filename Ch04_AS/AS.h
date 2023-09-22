#pragma once

#include <iostream>

typedef int ElementType;

class Node
{
public:
	ElementType Data;
};

class ArrayStack
{
public:
	int Capacity;
	int Top;
	Node* Nodes;
};

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);