#pragma once

class Node
{
public:
	char* Data;
	Node* NextNode;
};

class LinkedListStack
{
public:
	Node* Top;
	Node* List;
};

void LLS_CreateStack(LinkedListStack*& Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(const char* Data);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
bool LLS_IsEmpty(LinkedListStack* Stack);