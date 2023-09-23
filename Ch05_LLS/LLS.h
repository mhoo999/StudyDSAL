#pragma once
#include <iostream>

class Node
{
public:
	char* Data;
	Node* NextNode;
};

class LinkedListStack
{
public:
	Node* List;
	Node* Top;
};