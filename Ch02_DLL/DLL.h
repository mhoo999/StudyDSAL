#pragma once

#include <iostream>

typedef int ElementType;

typedef struct Node
{
	ElementType Data;
	struct Node* PrevNode;
	struct Node* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);